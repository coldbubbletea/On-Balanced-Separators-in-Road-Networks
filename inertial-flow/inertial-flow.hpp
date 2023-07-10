#ifndef INERTIAL_FLOW_HPP_
#define INERTIAL_FLOW_HPP_

#include "partitioner/bisection_graph_view.hpp"
#include "partitioner/dinic_max_flow.hpp"
#include"../spatial/Graph.hpp"




//Input parameters:
// a graph defined in spatial/Graph
DinicMaxFlow::MinCut computeInertialFlowCut(const BisectionGraphView &view,
                                            const std::size_t num_slopes,
                                            const double balance,
                                            const double source_sink_rate);


#endif 