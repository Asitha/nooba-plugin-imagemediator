#ifndef IMAGEMEDIATORPLUGIN_H
#define IMAGEMEDIATORPLUGIN_H

#include "imagemediatorplugin_global.h"
#include "noobapluginapi.h"

#include <QObject>

class IMAGEMEDIATORPLUGIN_EXPORT ImagemediatorPlugin: public NoobaPluginAPI
{
    Q_OBJECT
    Q_INTERFACES(NoobaPluginAPI)
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "nooba.plugins.qt5.imagemediator-plugin" FILE "imagemediatorPlugin.json")
#endif

public:
    ImagemediatorPlugin();
    ~ImagemediatorPlugin();

    bool procFrame(const cv::Mat &in, cv::Mat &out, ProcParams &params);
    bool init();
    bool release();
    PluginInfo getPluginInfo() const;

public slots:

    /**
     * These functions will be called when the parameters are changed by the
     * user.
     */
//    void onIntParamChanged(const QString& varName, int val);
//    void onDoubleParamChanged(const QString& varName, double val);
//    void onStringParamChanged(const QString& varName, const QString& val);
//    void onMultiValParamChanged(const QString& varName, const QString& val);
private:

    /*
     \brief get a color QImage from cv::Mat
     \return QImage with three color channels
     */
    inline QImage convertToQImage(const cv::Mat &cvImg);

};

#endif // IMAGEMEDIATORPLUGIN_H
