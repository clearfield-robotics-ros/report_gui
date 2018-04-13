//
// report_gui.h
//
// Created: 27 Feb 2017
// Author: Adam Plowcha

#ifndef __ROS_GUI_TEMPLATE_H__
#define __ROS_GUI_TEMPLATE_H__

#include <fstream>
#include <ros/ros.h>
#include <ros/master.h>
#include <pluginlib/class_list_macros.h>
#include <QStringList>
#include <ros/node_handle.h>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <rqt_gui_cpp/plugin.h>
#include <ui_report_gui.h>
#include <QWidget>
#include <QPainter>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int16.h>
#include <cmath>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <sstream>
#include <report_gui/detection_result.h>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

namespace report_gui {
//constants can go here if needed

class ReportGUI : public rqt_gui_cpp::Plugin
{
    Q_OBJECT
public:
    ReportGUI();
    virtual ~ReportGUI();
    virtual void initPlugin(qt_gui_cpp::PluginContext &context);
    virtual void shutdownPlugin();

Q_SIGNALS:
    void setReportText(const QString str);

private Q_SLOTS:
//This is where you name the
//functions that handle UI
//things like button presses, etc.

//Example - this is "connected" in the initPlugin function:
//void onBtnNorthClicked();


private:
    Ui::ReportGUIWidget ui_;
    QWidget *widget_;


    // ROS Stuff
	// Add any other ROS related items here if needed
	// This is also where you can put your own function definitions
	// and variables

    //Background map for drawing on
    QPixmap mapBGPixmap;
//    ros::NodeHandle ros_node_handle;
    ros::Subscriber current_state_sub;
    ros::Subscriber report_sub;
    ros::Publisher desired_state_pub;
//    void talkerClbk(const std_msgs::String &msg);
//    void talkerClbk(const std_msgs::Int32 &msg);
    void currentStateClbk(const std_msgs::Int16 &msg);
    void resultsClbk(const report_gui::detection_result &msg);
//    void formatOutput();
//    std::vector<int> mineCount(); // first entry: correct mines. second entry: correct nonmines
//    std::vector<bool> verifyUnderLimit(const std::vector<float> &data, const float &limit);
//    std::vector<std::string> id;
//    std::vector<int> id;
//    std::vector<bool> truth, estimate;
//    std::vector<float> radius_truth, x_truth, y_truth, radius_estimate, x_estimate, y_estimate, estimate_euclidean_error;
//    std::vector<float> warning_delay, probe_time;
    float max_dist, max_warning_delay, max_probe_time;
    int mine_threshold, nonmine_threshold;
   
};
}

#endif /* __ROS_GUI_TEMPLATE_H__ */
