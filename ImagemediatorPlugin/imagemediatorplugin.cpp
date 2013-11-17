#include "imagemediatorplugin.h"
#include <QtCore>
#include <QtGui/QImage>
#include <opencv2/core/core.hpp>

ImagemediatorPlugin::ImagemediatorPlugin()
{

}

ImagemediatorPlugin::~ImagemediatorPlugin()
{

}

bool ImagemediatorPlugin::procFrame( const cv::Mat &in, cv::Mat &out, ProcParams &params )
{
    Q_UNUSED(params)
    PluginPassData data;
    out = in;
    data.setImage(convertToQImage(out));

    emit outputData(data);
    return true;
}

bool ImagemediatorPlugin::init()
{
    //void createFrameViewer(const QString& title)
    createFrameViewer("TestOP");
    return true;
}

bool ImagemediatorPlugin::release()
{
    return true;
}

PluginInfo ImagemediatorPlugin::getPluginInfo() const
{
    PluginInfo pluginInfo(
        "Imagemediator Plugin",
        0,
        1,
        "Plugin Description goes here",
        "Plugin Creator");
    return pluginInfo;
}

void ImagemediatorPlugin::inputData(const PluginPassData &data)
{

    updateFrameViewer("TestOP",data.getImage());

    //emit outputData(data);
}

QImage ImagemediatorPlugin::convertToQImage(const cv::Mat &cvImg)
{
    return QImage((const unsigned char*)(cvImg.data),
                cvImg.cols,cvImg.rows,cvImg.step,  QImage::Format_RGB888);
}


// see qt4 documentation for details on the macro (Qt Assistant app)
// Mandatory  macro for plugins in qt4. Made obsolete in qt5
#if QT_VERSION < 0x050000
    Q_EXPORT_PLUGIN2(ImagemediatorPlugin, ImagemediatorPlugin);
#endif
