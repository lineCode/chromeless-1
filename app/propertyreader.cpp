// Qt includes
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

// Other includes
#include "propertyreader.h"

PropertyReader::PropertyReader(QObject *parent) :
    QObject(parent)
{
    _isAppVersionSet = false;
    _isAppNameSet = false;
    _isAppDescSet = false;
    _isAuthorNameSet = false;
    _isAuthorEmailSet = false;
    _isWinHeightSet = false;
    _isWinWidthSet = false;
    _isWinMaxWidthSet = false;
    _isWinMaxHeightSet = false;
    _isWinMinWidthSet = false;
    _isWinMinHeightSet = false;
    _isWinFixedWidthSet = false;
    _isWinFixedHeightSet = false;
    _isWinShowTitleBarSet = false;
    _isWinMaximizedSet = false;
}

void PropertyReader::readProperties(QString propFile)
{
    QFile file(propFile);
    file.open(QIODevice::ReadOnly);

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &err);

    // If error in parsing the document, then return
    if(err.error != QJsonParseError::NoError) {
        return;
    }

    QJsonObject jObj = doc.object();

    // App properties
    if(jObj.contains("version")) {
        _appVersion = jObj["version"].toString();
        _isAppVersionSet = true;
    }

    if(jObj.contains("name")) {
        _appName = jObj["name"].toString();
        _isAppNameSet = true;
    }

    if(jObj.contains("description")) {
        _appDesc = jObj["description"].toString();
        _isAppDescSet = true;
    }

    // Author properties
    if(jObj.contains("author")) {
        QJsonObject authorObj = jObj["author"].toObject();

        if(authorObj.contains("name")) {
            _authorName = authorObj["name"].toString();
            _isAuthorNameSet = true;
        }

        if(authorObj.contains("email")) {
            _authorEmail = authorObj["email"].toString();
            _isAuthorEmailSet = true;
        }
    }

    // Window properties
    if(jObj.contains("window")) {
        QJsonObject winObj = jObj["window"].toObject();

        if(winObj.contains("width")) {
            _winWidth = (int)winObj["width"].toDouble();
            _isWinWidthSet = true;
        }

        if(winObj.contains("height")) {
            _winHeight = (int)winObj["height"].toDouble();
            _isWinHeightSet = true;
        }

        if(winObj.contains("maxWidth")) {
            _winMaxWidth = (int)winObj["maxWidth"].toDouble();
            _isWinMaxWidthSet = true;
        }

        if(winObj.contains("maxHeight")) {
            _winMaxHeight = (int)winObj["maxHeight"].toDouble();
            _isWinMaxHeightSet = true;
        }

        if(winObj.contains("minWidth")) {
            _winMinWidth = (int)winObj["minWidth"].toDouble();
            _isWinMinWidthSet = true;
        }

        if(winObj.contains("minHeight")) {
            _winMinHeight = (int)winObj["minHeight"].toDouble();
            _isWinMinHeightSet = true;
        }

        if(winObj.contains("fixedWidth")) {
            _winFixedWidth = (int)winObj["fixedWidth"].toDouble();
            _isWinFixedWidthSet = true;
        }

        if(winObj.contains("fixedHeight")) {
            _winFixedHeight = (int)winObj["fixedHeight"].toDouble();
            _isWinFixedHeightSet = true;
        }

        if(winObj.contains("showTitleBar")) {
            _winShowTitleBar = winObj["showTitleBar"].toBool();
            _isWinShowTitleBarSet = true;
        }

        if(winObj.contains("maximized")) {
            _winMaximized = winObj["maximized"].toBool();
            _isWinMaximizedSet = true;
        }
    }

    file.close();
}

QString PropertyReader::appVersion()
{
    return _appVersion;
}

QString PropertyReader::appName()
{
    return _appName;
}

QString PropertyReader::appDesc()
{
    return _appDesc;
}

QString PropertyReader::authorName()
{
    return _authorName;
}

QString PropertyReader::authorEmail()
{
    return _authorEmail;
}

int PropertyReader::windowHeight()
{
    return _winHeight;
}

int PropertyReader::windowWidth()
{
    return _winWidth;
}

int PropertyReader::windowMaxWidth()
{
    return _winMaxWidth;
}

int PropertyReader::windowMaxHeight()
{
    return _winMaxHeight;
}

int PropertyReader::windowMinWidth()
{
    return _winMinWidth;
}

int PropertyReader::windowMinHeight()
{
    return _winMinHeight;
}

int PropertyReader::windowFixedWidth()
{
    return _winFixedWidth;
}

int PropertyReader::windowFixedHeight()
{
    return _winFixedHeight;
}

bool PropertyReader::windowShowTitleBar()
{
    return _winShowTitleBar;
}

bool PropertyReader::windowMaximized()
{
    return _winMaximized;
}

bool PropertyReader::isAppVersionSet()
{
    return _isAppVersionSet;
}

bool PropertyReader::isAppNameSet()
{
    return _isAppNameSet;
}

bool PropertyReader::isAppDescSet()
{
    return _isAppDescSet;
}

bool PropertyReader::isAuthorNameSet()
{
    return _isAuthorNameSet;
}

bool PropertyReader::isAuthorEmailSet()
{
    return _isAuthorEmailSet;
}

bool PropertyReader::isWindowHeightSet()
{
    return _isWinHeightSet;
}

bool PropertyReader::isWindowWidthSet()
{
    return _isWinWidthSet;
}

bool PropertyReader::isWindowMaxHeightSet()
{
    return _isWinMaxHeightSet;
}

bool PropertyReader::isWindowMaxWidthSet()
{
    return _isWinMaxWidthSet;
}

bool PropertyReader::isWindowMinHeightSet()
{
    return _isWinMinHeightSet;
}

bool PropertyReader::isWindowMinWidthSet()
{
    return _isWinMinWidthSet;
}

bool PropertyReader::isWindowFixedHeightSet()
{
    return _isWinFixedHeightSet;
}

bool PropertyReader::isWindowFixedWidthSet()
{
    return _isWinFixedWidthSet;
}

bool PropertyReader::isWindowShowTitleBarSet()
{
    return _isWinShowTitleBarSet;
}

bool PropertyReader::isWindowMaximizedSet()
{
    return _isWinMaximizedSet;
}
