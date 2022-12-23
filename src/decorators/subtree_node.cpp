#include "behaviortree_cpp/decorators/subtree_node.h"

BT::SubTreeNode::SubTreeNode(const std::string& instance_name,
                             const NodeConfig& config) :
  DecoratorNode(instance_name, config)
{
  setRegistrationID("SubTree");
}

BT::NodeStatus BT::SubTreeNode::tick()
{
  NodeStatus prev_status = status();
  if (prev_status == NodeStatus::IDLE)
  {
    setStatus(NodeStatus::RUNNING);
  }
  auto status = child_node_->executeTick();
  if(status != NodeStatus::RUNNING)
  {
    resetChild();
  }

  return status;
}
