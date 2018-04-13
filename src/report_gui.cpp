//
// report_gui.cpp
//
// Created: 27 Feb 2017
// Author: Adam Plowcha
//


#include <report_gui.h>


namespace report_gui
{

ReportGUI::ReportGUI() :
    rqt_gui_cpp::Plugin(), widget_(0)
{
    setObjectName("ReportGUI");
}

ReportGUI::~ReportGUI()
{

}

void ReportGUI::initPlugin(qt_gui_cpp::PluginContext &context)
{
    std::string full_name_space = getNodeHandle().getNamespace();
    std::vector<std::string> components;
    boost::split(components, full_name_space, boost::is_any_of("/"));
    components.pop_back();
    std::string name_space = boost::algorithm::join(components, "/");

    /* Setup the widget */
    widget_ = new QWidget();
    ui_.setupUi(widget_);
    context.addWidget(widget_);

    // Status Reporting Boxes
    QObject::connect( this, SIGNAL(setReportText(const QString)),
                ui_.report, SLOT(setText(const QString)));

    current_state_sub = getNodeHandle().subscribe("/current_state", 1000, &ReportGUI::currentStateClbk, this);
    report_sub = getNodeHandle().subscribe("/results", 1000, &ReportGUI::resultsClbk, this);
    desired_state_pub = getNodeHandle().advertise<std_msgs::Int16>("desired_state",1000);

    // read parameters from launch file
    getNodeHandle().getParam("/report_gui/report_gui/max_dist",max_dist);
    getNodeHandle().getParam("/report_gui/report_gui/max_warning_delay",max_warning_delay);
    getNodeHandle().getParam("/report_gui/report_gui/max_probe_time",max_probe_time);
    getNodeHandle().getParam("/report_gui/report_gui/mine_threshold",mine_threshold);
    getNodeHandle().getParam("/report_gui/report_gui/nonmine_threshold",nonmine_threshold);


}

void ReportGUI::shutdownPlugin()
{
    //Shutdown pubs and subs, etc
}

//All your remaining functions to go here...

void ReportGUI::currentStateClbk(const std_msgs::Int16 &msg)
{
    switch(msg.data){
    case 0: // Idle
        emit setReportText("This just in...");
        break;
     }
}

void ReportGUI::resultsClbk(const report_gui::detection_result &msg)
{
//    id.push_back(boost::lexical_cast<std::string>(msg.id));
//    truth.push_back(msg.truth);
//    radius_truth.push_back(boost::lexical_cast<std::string>(boost::format("%.2f") % msg.radius_truth));
//    x_truth.push_back(boost::lexical_cast<std::string>(boost::format("%.2f") % msg.x_truth));
//    y_truth.push_back(boost::lexical_cast<std::string>(boost::format("%.2f") % msg.y_truth));
//    estimate.push_back(msg.estimate);
//    radius_estimate.push_back(boost::lexical_cast<std::string>(boost::format("%.2f") % msg.radius_estimate));
//    x_estimate.push_back(boost::lexical_cast<std::string>(boost::format("%.2f") % msg.x_estimate));
//    y_estimate.push_back(boost::lexical_cast<std::string>(boost::format("%.2f") % msg.y_estimate));
//    estimate_euclidean_error.push_back(boost::lexical_cast<std::string>(boost::format("%.2f") % msg.estimate_euclidean_error));
//    warning_delay.push_back(boost::lexical_cast<std::string>(boost::format("%.2f") % msg.warning_delay));
//    probe_time.push_back(boost::lexical_cast<std::string>(boost::format("%.2f") % msg.probe_time));
//    id.push_back(msg.id);
//    truth.push_back(msg.truth);
//    radius_truth.push_back(msg.radius_truth);
//    x_truth.push_back(msg.x_truth);
//    y_truth.push_back(msg.y_truth);
//    estimate.push_back(msg.estimate);
//    radius_estimate.push_back(msg.radius_estimate);
//    x_estimate.push_back(msg.x_estimate);
//    y_estimate.push_back(msg.y_estimate);
//    estimate_euclidean_error.push_back(msg.estimate_euclidean_error);
//    warning_delay.push_back(msg.warning_delay);
//    probe_time.push_back(msg.probe_time);
}

}

//This is a required line for Qt and ROS to work together
PLUGINLIB_EXPORT_CLASS(report_gui::ReportGUI, rqt_gui_cpp::Plugin)
