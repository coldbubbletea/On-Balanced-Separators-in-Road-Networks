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

makeSpatialOrder(const double slope)


{
     const auto project_value = [slope](const auto &node) {
        auto lon = static_cast<std::int32_t>(node.coordinate.lon);
        auto lat = static_cast<std::int32_t>(node.coordinate.lat);

        return slope * lon + (1. - std::fabs(slope)) * lat;
    };

        const auto spatially = [&](const auto &lhs, const auto &rhs) {
        return project(lhs) < project(rhs);
    };
}



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