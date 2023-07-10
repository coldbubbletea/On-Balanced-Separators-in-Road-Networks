#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iterator>
#include <mutex>
#include <set>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>
#include <tbb/blocked_range.h>
#include <tbb/parallel_for.h>
#include "util.hpp"
#include"../spatial/Graph.hpp"
struct SpatialOrder
{
    std::unordered_set<Spatial::Node> sources;
    std::unordered_set<Spatial::Node> sinks;
};



SpatialOrder makeSpatialOrder(const BisectionGraphView &view, const double ratio, const double slope)
{


    using Embedding = std::vector<Node>;

    Embedding embedding;
    embedding.reserve(view.NumberOfNodes());

    // adress of the very first node
    const auto node_zero = &(*view.Begin());

    const auto project = [slope](const auto &node) {
        auto lon = static_cast<std::int32_t>(node.lon);
        auto lat = static_cast<std::int32_t>(node.lat);

        return slope * lon + (1. - std::fabs(slope)) * lat;
    };

    const auto spatially = [&](const auto &lhs, const auto &rhs) {
        return project(lhs) < project(rhs);
    };

    const std::size_t n = ratio * embedding.size();

    util::reorderFirstLast(embedding, n, spatially);

    SpatialOrder order;

    order.sources.reserve(n);
    order.sinks.reserve(n);

    for (auto it = begin(embedding), last = begin(embedding) + n; it != last; ++it)
        order.sources.insert(it->nid);

    for (auto it = end(embedding) - n, last = end(embedding); it != last; ++it)
        order.sinks.insert(it->nid);

    return order;
}



    tbb::blocked_range<std::size_t> range{0, n, 1};
    auto best_balance = 1;
    std::mutex lock;
    tbb::parallel_for(range, [&](const auto &chunk) {
        for (auto round = chunk.begin(), end = chunk.end(); round != end; ++round)
        {
            const auto slope = -1. + round * (2. / n);

            auto order = makeSpatialOrder(view, ratio, slope);
            auto cut = DinicMaxFlow()(view, order.sources, order.sinks);
            auto cut_balance = get_balance(cut.num_nodes_source);

            {
                std::lock_guard<std::mutex> guard{lock};

                // Swap to keep the destruction of the old object outside of critical section.
                if (cut.num_edges * cut_balance < best.num_edges * best_balance ||
                    (cut.num_edges == best.num_edges &&
                     balance_delta(cut.num_nodes_source) < balance_delta(best.num_nodes_source)))
                {
                    best_balance = cut_balance;
                    std::swap(best, cut);
                }
            }
            // cut gets destroyed here
        }
    });




DinicMaxFlow::MinCut computeInertialFlowCut(const BisectionGraphView &view,
                                            const std::size_t num_slopes,
                                            const double balance,
                                            const double source_sink_rate)
{
    return bestMinCut(view, num_slopes, source_sink_rate, balance);
}