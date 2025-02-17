﻿/*
 * @file 	ctrlbar.h
 * @date 	2018/01/07 10:46
 *
 * @author 	itisyang
 * @Contact	itisyang@gmail.com
 *
 * @brief 	控制面板界面
 * @note
 */
#ifndef CTRLBAR_H
#define CTRLBAR_H

#include <QWidget>
#include "CustomSlider.h"

namespace Ui {
class CtrlBar;
}

class CtrlBar : public QWidget
{
    Q_OBJECT

public:
    explicit CtrlBar(QWidget *parent = 0);
    ~CtrlBar();
	/**
	 * @brief	初始化UI
	 * 
	 * @return	true 成功 false 失败
	 * @note 	
	 */
    bool Init();

public:
    void SlotVideoTotalSeconds(int nSeconds);
    void SlotVideoPlaySeconds(int nSeconds);
    void SlotVideoVolume(double dPercent);
    void SlotPauseStatus(bool bPaused);
    void SlotStopFinished();
    void SlotSpeed(float speed);
    void SlotPlaySliderValueChanged();
    void SlotVolumeSliderValueChanged();
private slots:
    void on_PlayOrPauseBtn_clicked();
    void on_VolumeBtn_clicked();
    void on_StopBtn_clicked();
    void on_SettingBtn_clicked();

    /**
    * @brief	连接信号槽
    *
    * @param
    * @return
    * @note
    */
    bool ConnectSignalSlots();
    void on_speedBtn_clicked();

signals:
    void SigShowOrHidePlaylist();	//< 显示或隐藏信号
    void SigPlaySeek(double dPercent); ///< 调整播放进度
    void SigPlayVolume(double dPercent);
    void SigPlayOrPause();
    void SigStop();
    void SigForwardPlay();
    void SigBackwardPlay();
    void SigShowMenu();
    void SigShowSetting();
    void SigSpeed();
private:
    Ui::CtrlBar *ui;

    int m_nTotalPlaySeconds;
    double m_dLastVolumePercent;
};

#endif // CTRLBAR_H
