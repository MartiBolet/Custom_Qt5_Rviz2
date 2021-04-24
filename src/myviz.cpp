
#include "myviz/myviz.hpp"

MyViz::MyViz(rviz_common::VisualizationFrame* frame,
         rviz_common::ros_integration::RosNodeAbstractionIface::WeakPtr ros_node_abs,
         QWidget* parent)
  : QMainWindow(parent)
  , frame_(frame)
  , ros_node_abs_(ros_node_abs)
{

    /*-----------------------------
        CONSTRUCT LAYOUT
    -----------------------------*/
    QLabel* thickness_label = new QLabel("Line Thickness");
    QSlider* thickness_slider = new QSlider(Qt::Horizontal);
    thickness_slider->setMinimum(1);
    thickness_slider->setMaximum(100);
    QLabel* cell_size_label = new QLabel("Cell Size");
    QSlider* cell_size_slider = new QSlider(Qt::Horizontal);
    cell_size_slider->setMinimum(1);
    cell_size_slider->setMaximum(100);
    QGridLayout* controls_layout = new QGridLayout();
    controls_layout->addWidget(thickness_label, 0, 0);
    controls_layout->addWidget(thickness_slider, 0, 1);
    controls_layout->addWidget(cell_size_label, 1, 0);
    controls_layout->addWidget(cell_size_slider, 1, 1);

    /*-----------------------------
        INIT MAIN RVIZ CLASSES
    -----------------------------*/
    manager_ = frame_->getManager();
    manager_-> removeAllDisplays ();
    render_panel_ = frame_->getRenderPanel();

    /*-----------------------------
        ADD VISUALIZATION
    -----------------------------*/
    main_layout = new QVBoxLayout;
    main_layout->addLayout(controls_layout);

    central_widget = new QWidget();
    main_layout->setSpacing(0);
    main_layout->setMargin(0);

    central_widget->setLayout(main_layout);
    setCentralWidget(central_widget);
    main_layout->addWidget(render_panel_);

    /*-----------------------------
            SIGNALS &
    -----------------------------*/
    connect(thickness_slider, SIGNAL(valueChanged(int)), this, SLOT(setThickness(int)));
    connect(cell_size_slider, SIGNAL(valueChanged(int)), this, SLOT(setCellSize(int)));

    /*-----------------------------
          DISPLAYS INIT
    -----------------------------*/
    DisplayGrid();

    /*-----------------------------
            INIT SLIDER
    -----------------------------*/
    thickness_slider->setValue( 25 );
    cell_size_slider->setValue( 10 );
    
}

MyViz::~MyViz()
{
    delete frame_;
}

void MyViz::DisplayGrid()
{
    grid_ = manager_->createDisplay("rviz_default_plugins/Grid", "adjustable grid", true);
    assert(grid_!= NULL);
    grid_->subProp("Line Style")->setValue("Billboards");
    grid_->subProp("Color")->setValue(QColor(Qt::yellow)); 
}

      
void MyViz::setThickness( int thickness_percent) {
    if( grid_ != NULL ) {
        grid_->subProp("Line Style")->subProp("Line Width")->setValue(thickness_percent / 100.0f);
    }
}

void MyViz::setCellSize( int cell_size_percent ) {
    if(grid_ != NULL) {
        grid_->subProp("Cell Size")->setValue(cell_size_percent / 10.0f);
    }
}

/*****************************************************************************
 ** Mainwindow CLOSE
*****************************************************************************/
void MyViz::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
    rclcpp::shutdown();
}