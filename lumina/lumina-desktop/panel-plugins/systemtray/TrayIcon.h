//===========================================
//  Lumina-DE source code
//  Copyright (c) 2014, Ken Moore
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
//  Note: The basic idea behind this class that that it puts the app window
//    in the same spot as the tray icon (to directly pass mouse events and such), 
//    while keeping the tray icon visual in sync with the app window
//===========================================
#ifndef _LUMINA_PANEL_PLUGIN_SYSTEM_TRAY_ICON_H
#define _LUMINA_PANEL_PLUGIN_SYSTEM_TRAY_ICON_H

//Qt includes
#include <QX11EmbedContainer>
#include <QTimer>
#include <QMoveEvent>
#include <QIcon>
#include <QPixmap>

// libLumina includes
#include <LuminaX11.h>

//Local includes

class TrayIcon : public QX11EmbedContainer{
	Q_OBJECT
public:
	TrayIcon(QWidget* parent = 0);
	~TrayIcon();

	WId appID(); //the ID for the attached application
	void attachApp(WId id);
	void setSizeSquare(int side);

public slots:
	void detachApp();

private:
	WId IID, AID; //icon ID and app ID

private slots:
	void slotAttach(); //so that the attachment can be done in a new thread
	void updateIcon();

protected:
	void draw(QPaintEvent *event);
	//void moveEvent(QMoveEvent *event);
	//bool x11Event(XEvent *event);

signals:
	void AppClosed();
	void AppAttached();
};
#endif