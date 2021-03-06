
#include <QApplication>
#include <rclcpp/rclcpp.hpp>
#include "myviz/myviz.hpp"

int main(int argc, char **argv)
{
    // Init QT app
    QApplication app(argc, argv);
    // Init ROS2
    rclcpp::init(argc, argv);

    // Initialize the VisualizationFrame
    auto ros_node_abs = std::make_shared<rviz_common::ros_integration::RosNodeAbstraction>("rviz_render_node");
    rviz_common::VisualizationFrame* frame = new rviz_common::VisualizationFrame(ros_node_abs);
    frame->setApp(&app);
    frame->initialize(ros_node_abs, NULL);

    // Create MainWindow and initialize it
    auto mainWind_ = std::make_shared<MyViz>(frame, ros_node_abs);
    mainWind_->show();

    while (rclcpp::ok()) {
        app.processEvents();
    }

    return 0;
}