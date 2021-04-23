#ifndef MY_VIZ_HPP
#define MY_VIZZ_HPP

// Qt impots
#include <QLabel>
#include <QWidget>
#include <QSlider>
#include <QMainWindow>
#include <QGridLayout>

// Rviz2 imports
#include "rclcpp/clock.hpp"
#include "rviz_common/render_panel.hpp"
#include "rviz_common/display.hpp"
#include <rviz_common/display_context.hpp>
#include "rviz_common/ros_integration/ros_node_abstraction_iface.hpp"
#include "rviz_common/ros_integration/ros_client_abstraction.hpp"
#include "rviz_common/ros_integration/ros_node_abstraction.hpp"
#include "rviz_common/visualization_manager.hpp"
#include "rviz_common/panel_factory.hpp"
#include "rviz_common/visualization_frame.hpp"


class MyViz: public QMainWindow
{
    Q_OBJECT
  public:
    MyViz(rviz_common::VisualizationFrame* frame,
         rviz_common::ros_integration::RosNodeAbstractionIface::WeakPtr ros_node_abs,
         QWidget* parent = 0 );
    virtual ~MyViz();

    void setApp(QApplication * app);
    // Call initialize() after setApp
    void initialize();

  private Q_SLOTS:
    void setThickness( int thickness_percent );
    void setCellSize( int cell_size_percent );

  private:
    // Visualization vars
    QVBoxLayout* main_layout;

    // Rviz vars
    rviz_common::VisualizationFrame* frame_;
    rviz_common::VisualizationManager* manager_;
    rviz_common::RenderPanel* render_panel_;
    rviz_common::Display* grid_;
    rviz_common::ros_integration::RosNodeAbstractionIface::WeakPtr ros_node_abs_;
};

#endif // MY_VIZZ_HPP