/**
 ******************************************************************************
 *
 * @file       scopegadgetoptionspage.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup ScopePlugin Scope Gadget Plugin
 * @{
 * @brief The scope Gadget, graphically plots the states of UAVObjects
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef SCOPEGADGETOPTIONSPAGE_H
#define SCOPEGADGETOPTIONSPAGE_H

#include "coreplugin/dialogs/ioptionspage.h"

#include "scopegadgetconfiguration.h"
#include "ui_scopegadgetoptionspage.h"

#include <QString>
#include <QStringList>
#include <QDebug>
#include <QtGui/QColorDialog>

namespace Core
{
class IUAVGadgetConfiguration;
}

class ScopeGadgetConfiguration;

namespace Ui
{
class ScopeGadgetOptionsPage;
}

using namespace Core;

class ScopeGadgetOptionsPage :  public IOptionsPage
{
    Q_OBJECT
public:
    explicit ScopeGadgetOptionsPage(ScopeGadgetConfiguration *config, QObject *parent = 0);

    QWidget *createPage(QWidget *parent);
    void apply();
    void finish();

private:
    Ui::ScopeGadgetOptionsPage *options_page;
    ScopeGadgetConfiguration *m_config;

    void addPlotCurveConfig(QString uavObject, QString uavField, int scale, QVariant varColor);
    void setCurvePlotProperties(QListWidgetItem *listWidgetItem, QString uavObject, QString uavField, int scale, QVariant varColor);
    void setYAxisWidgetFromPlotCurve();
    void setButtonColor(const QColor &color);

private slots:
    void on_lstCurves_currentRowChanged(int currentRow);
    void on_btnRemoveCurve_clicked();
    void on_btnAddCurve_clicked();
    void on_cmbUAVObjects_currentIndexChanged(QString val);    
    void on_btnColor_clicked();
    void on_loggingEnable_clicked();

};

#endif // SCOPEGADGETOPTIONSPAGE_H
