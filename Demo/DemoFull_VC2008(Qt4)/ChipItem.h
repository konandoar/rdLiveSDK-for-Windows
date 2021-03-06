﻿#ifndef CHIPITEM_H
#define CHIPITEM_H

#include <QWidget>
#include "ui_chipitem.h"
#include "chipitemoper.h"
class ChipItem : public QWidget
{
	Q_OBJECT

public:
	ChipItem( HCHIP hChip, QListWidget *parent = 0);
	~ChipItem();

	HCHIP GetHChip() { return m_hChip; }
	static BOOL OnRenderNotify( QListWidget* pList, IRender_ENotify eNotify, HSCENE hScene, int iValue );
	static HCHIP GetChipHandle( QListWidget* pList, int iViewIndex );
	void OnChipSelected( BOOL bSelect = TRUE );
private:
	Ui::ChipItem ui;
	HCHIP			m_hChip;
	IPinInput_EClass	m_eClassType;
	QSize			m_siBase;
	static ChipItemOper*	m_pItemOper;

	QListWidget*		m_listWidChips;
	QListWidgetItem*	m_lwItem;
	void DisplaySourceName();
	void SetLabelIcon( IPinInput_SStatusInfo& sChipStatus );

	void OnStatusChanged();
	void OnPosChanged();
	static ChipItem* GetChipItem( QListWidget* pList, int iViewIndex );
	static BOOL MoveChipItem( QListWidget* pList, int iViewFrom, int iViewTo );
public slots:
	void on_chkHideChip_clicked( bool checked );
	void on_chkLockAspect_clicked( bool checked );
	void on_chkLockPos_clicked( bool checked );
	void on_chkLockSize_clicked( bool checked );
	void on_chkLockAngle_clicked( bool checked );

	void on_butMiddle_clicked( bool checked );
	void on_butScaleFull_clicked( bool checked );


};


#endif // CHIPITEM_H
