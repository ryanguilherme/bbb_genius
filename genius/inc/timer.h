#ifndef TIMER_H_
#define TIMER_H_
/*
 * =====================================================================================
 *
 *       Filename:  timer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  31/05/2018 19:52:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Francisco Helder (FHC), helderhdw@gmail.com
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

#include "soc_AM335x.h"
#include "hw_types.h"
#include "clock_module.h"
#include "control_module.h"

//#define INTERRUPT

/*************************************************************************\
 * Registers Definition
\*************************************************************************/

#define DMTIMER_TIDR   (0x0)
#define DMTIMER_TIOCP_CFG   (0x10)
#define DMTIMER_IRQ_EOI   (0x20)
#define DMTIMER_IRQSTATUS_RAW   (0x24)
#define DMTIMER_IRQSTATUS   (0x28)
#define DMTIMER_IRQENABLE_SET   (0x2C)
#define DMTIMER_IRQENABLE_CLR   (0x30)
#define DMTIMER_IRQWAKEEN   (0x34)
#define DMTIMER_TCLR   (0x38)
#define DMTIMER_TCRR   (0x3C)
#define DMTIMER_TLDR   (0x40)
#define DMTIMER_TTGR   (0x44)
#define DMTIMER_TWPS   (0x48)
#define DMTIMER_TMAR   (0x4C)
#define DMTIMER_TCAR(n)   (0x50 + (((n) - 1) * 8))
#define DMTIMER_TSICR   (0x54)

/**************************************************************************\ 
 * Field Definition Macros
\**************************************************************************/

/* TIDR */
#define DMTIMER_TIDR_CUSTOM   (0x000000C0u)
#define DMTIMER_TIDR_CUSTOM_SHIFT   (0x00000006u)

#define DMTIMER_TIDR_FUNC   (0x0FFF0000u)
#define DMTIMER_TIDR_FUNC_SHIFT   (0x00000010u)

#define DMTIMER_TIDR_R_RTL   (0x0000F800u)
#define DMTIMER_TIDR_R_RTL_SHIFT   (0x0000000Bu)

#define DMTIMER_TIDR_SCHEME   (0xC0000000u)
#define DMTIMER_TIDR_SCHEME_SHIFT   (0x0000001Eu)
#define DMTIMER_TIDR_SCHEME_HIGHLANDER0P8   (0x1u)
#define DMTIMER_TIDR_SCHEME_LEGACY   (0x0u)

#define DMTIMER_TIDR_X_MAJOR   (0x00000700u)
#define DMTIMER_TIDR_X_MAJOR_SHIFT   (0x00000008u)

#define DMTIMER_TIDR_Y_MINOR   (0x0000003Fu)
#define DMTIMER_TIDR_Y_MINOR_SHIFT   (0x00000000u)


/* TIOCP_CFG */
#define DMTIMER_TIOCP_CFG_EMUFREE   (0x00000002u)
#define DMTIMER_TIOCP_CFG_EMUFREE_SHIFT   (0x00000001u)
#define DMTIMER_TIOCP_CFG_EMUFREE_TIMER_FREE   (0x1u)
#define DMTIMER_TIOCP_CFG_EMUFREE_TIMER_FROZEN   (0x0u)

#define DMTIMER_TIOCP_CFG_IDLEMODE   (0x0000000Cu)
#define DMTIMER_TIOCP_CFG_IDLEMODE_SHIFT   (0x00000002u)
#define DMTIMER_TIOCP_CFG_IDLEMODE_FORCE   (0x0u)
#define DMTIMER_TIOCP_CFG_IDLEMODE_NOIDLE   (0x1u)
#define DMTIMER_TIOCP_CFG_IDLEMODE_SMART   (0x2u)
#define DMTIMER_TIOCP_CFG_IDLEMODE_WAKEUP   (0x3u)

#define DMTIMER_TIOCP_CFG_SOFTRESET   (0x00000001u)
#define DMTIMER_TIOCP_CFG_SOFTRESET_SHIFT   (0x00000000u)
#define DMTIMER_TIOCP_CFG_SOFTRESET_DONE   (0x0u)
#define DMTIMER_TIOCP_CFG_SOFTRESET_INITIATE   (0x1u)
#define DMTIMER_TIOCP_CFG_SOFTRESET_ONGOING   (0x1u)


/* IRQ_EOI */
#define DMTIMER_IRQ_EOI_LINE_NUMBER   (0x00000001u)
#define DMTIMER_IRQ_EOI_LINE_NUMBER_SHIFT   (0x00000000u)


/* IRQSTATUS_RAW */
#define DMTIMER_IRQSTATUS_RAW_MAT_IT_FLAG   (0x00000001u)
#define DMTIMER_IRQSTATUS_RAW_MAT_IT_FLAG_SHIFT   (0x00000000u)
#define DMTIMER_IRQSTATUS_RAW_MAT_IT_FLAG_NONE   (0x0u)
#define DMTIMER_IRQSTATUS_RAW_MAT_IT_FLAG_PENDING   (0x1u)
#define DMTIMER_IRQSTATUS_RAW_MAT_IT_FLAG_SET   (0x1u)

#define DMTIMER_IRQSTATUS_RAW_OVF_IT_FLAG   (0x00000002u)
#define DMTIMER_IRQSTATUS_RAW_OVF_IT_FLAG_SHIFT   (0x00000001u)
#define DMTIMER_IRQSTATUS_RAW_OVF_IT_FLAG_NONE   (0x0u)
#define DMTIMER_IRQSTATUS_RAW_OVF_IT_FLAG_PENDING   (0x1u)
#define DMTIMER_IRQSTATUS_RAW_OVF_IT_FLAG_SET   (0x1u)

#define DMTIMER_IRQSTATUS_RAW_TCAR_IT_FLAG   (0x00000004u)
#define DMTIMER_IRQSTATUS_RAW_TCAR_IT_FLAG_SHIFT   (0x00000002u)
#define DMTIMER_IRQSTATUS_RAW_TCAR_IT_FLAG_NONE   (0x0u)
#define DMTIMER_IRQSTATUS_RAW_TCAR_IT_FLAG_PENDING   (0x1u)
#define DMTIMER_IRQSTATUS_RAW_TCAR_IT_FLAG_SET   (0x1u)


/* IRQSTATUS */
#define DMTIMER_IRQSTATUS_MAT_IT_FLAG   (0x00000001u)
#define DMTIMER_IRQSTATUS_MAT_IT_FLAG_SHIFT   (0x00000000u)
#define DMTIMER_IRQSTATUS_MAT_IT_FLAG_CLEAR   (0x1u)
#define DMTIMER_IRQSTATUS_MAT_IT_FLAG_NONE   (0x0u)
#define DMTIMER_IRQSTATUS_MAT_IT_FLAG_PENDING   (0x1u)

#define DMTIMER_IRQSTATUS_OVF_IT_FLAG   (0x00000002u)
#define DMTIMER_IRQSTATUS_OVF_IT_FLAG_SHIFT   (0x00000001u)
#define DMTIMER_IRQSTATUS_OVF_IT_FLAG_CLEAR   (0x1u)
#define DMTIMER_IRQSTATUS_OVF_IT_FLAG_NONE   (0x0u)
#define DMTIMER_IRQSTATUS_OVF_IT_FLAG_PENDING   (0x1u)

#define DMTIMER_IRQSTATUS_TCAR_IT_FLAG   (0x00000004u)
#define DMTIMER_IRQSTATUS_TCAR_IT_FLAG_SHIFT   (0x00000002u)
#define DMTIMER_IRQSTATUS_TCAR_IT_FLAG_CLEAR   (0x1u)
#define DMTIMER_IRQSTATUS_TCAR_IT_FLAG_NONE   (0x0u)
#define DMTIMER_IRQSTATUS_TCAR_IT_FLAG_PENDING   (0x1u)


/* IRQENABLE_SET */
#define DMTIMER_IRQENABLE_SET_MAT_EN_FLAG   (0x00000001u)
#define DMTIMER_IRQENABLE_SET_MAT_EN_FLAG_SHIFT   (0x00000000u)
#define DMTIMER_IRQENABLE_SET_MAT_EN_FLAG_DISABLED   (0x0u)
#define DMTIMER_IRQENABLE_SET_MAT_EN_FLAG_ENABLE   (0x1u)
#define DMTIMER_IRQENABLE_SET_MAT_EN_FLAG_ENABLED   (0x1u)

#define DMTIMER_IRQENABLE_SET_OVF_EN_FLAG   (0x00000002u)
#define DMTIMER_IRQENABLE_SET_OVF_EN_FLAG_SHIFT   (0x00000001u)
#define DMTIMER_IRQENABLE_SET_OVF_EN_FLAG_DISABLED   (0x0u)
#define DMTIMER_IRQENABLE_SET_OVF_EN_FLAG_ENABLE   (0x1u)
#define DMTIMER_IRQENABLE_SET_OVF_EN_FLAG_ENABLED   (0x1u)

#define DMTIMER_IRQENABLE_SET_TCAR_EN_FLAG   (0x00000004u)
#define DMTIMER_IRQENABLE_SET_TCAR_EN_FLAG_SHIFT   (0x00000002u)
#define DMTIMER_IRQENABLE_SET_TCAR_EN_FLAG_DISABLED   (0x0u)
#define DMTIMER_IRQENABLE_SET_TCAR_EN_FLAG_ENABLE   (0x1u)
#define DMTIMER_IRQENABLE_SET_TCAR_EN_FLAG_ENABLED   (0x1u)


/* IRQENABLE_CLR */
#define DMTIMER_IRQENABLE_CLR_MAT_EN_FLAG   (0x00000001u)
#define DMTIMER_IRQENABLE_CLR_MAT_EN_FLAG_SHIFT   (0x00000000u)
#define DMTIMER_IRQENABLE_CLR_MAT_EN_FLAG_DISABLE   (0x1u)
#define DMTIMER_IRQENABLE_CLR_MAT_EN_FLAG_DISABLED   (0x0u)
#define DMTIMER_IRQENABLE_CLR_MAT_EN_FLAG_ENABLED   (0x1u)

#define DMTIMER_IRQENABLE_CLR_OVF_EN_FLAG   (0x00000002u)
#define DMTIMER_IRQENABLE_CLR_OVF_EN_FLAG_SHIFT   (0x00000001u)
#define DMTIMER_IRQENABLE_CLR_OVF_EN_FLAG_DISABLE   (0x1u)
#define DMTIMER_IRQENABLE_CLR_OVF_EN_FLAG_DISABLED   (0x0u)
#define DMTIMER_IRQENABLE_CLR_OVF_EN_FLAG_ENABLED   (0x1u)

#define DMTIMER_IRQENABLE_CLR_TCAR_EN_FLAG   (0x00000004u)
#define DMTIMER_IRQENABLE_CLR_TCAR_EN_FLAG_SHIFT   (0x00000002u)
#define DMTIMER_IRQENABLE_CLR_TCAR_EN_FLAG_DISABLE   (0x1u)
#define DMTIMER_IRQENABLE_CLR_TCAR_EN_FLAG_DISABLED   (0x0u)
#define DMTIMER_IRQENABLE_CLR_TCAR_EN_FLAG_ENABLED   (0x1u)


/* IRQWAKEEN */
#define DMTIMER_IRQWAKEEN_MAT_WUP_ENA   (0x00000001u)
#define DMTIMER_IRQWAKEEN_MAT_WUP_ENA_SHIFT   (0x00000000u)
#define DMTIMER_IRQWAKEEN_MAT_WUP_ENA_DISABLE   (0x0u)
#define DMTIMER_IRQWAKEEN_MAT_WUP_ENA_ENABLE   (0x1u)

#define DMTIMER_IRQWAKEEN_OVF_WUP_ENA   (0x00000002u)
#define DMTIMER_IRQWAKEEN_OVF_WUP_ENA_SHIFT   (0x00000001u)
#define DMTIMER_IRQWAKEEN_OVF_WUP_ENA_DISABLE   (0x0u)
#define DMTIMER_IRQWAKEEN_OVF_WUP_ENA_ENABLE   (0x1u)

#define DMTIMER_IRQWAKEEN_TCAR_WUP_ENA   (0x00000004u)
#define DMTIMER_IRQWAKEEN_TCAR_WUP_ENA_SHIFT   (0x00000002u)
#define DMTIMER_IRQWAKEEN_TCAR_WUP_ENA_DISABLE   (0x0u)
#define DMTIMER_IRQWAKEEN_TCAR_WUP_ENA_ENABLE   (0x1u)


/* TCLR */
#define DMTIMER_TCLR_AR   (0x00000002u)
#define DMTIMER_TCLR_AR_SHIFT   (0x00000001u)
#define DMTIMER_TCLR_AR_AUTO   (0x1u)
#define DMTIMER_TCLR_AR_ONESHOT   (0x0u)

#define DMTIMER_TCLR_CAPT_MODE   (0x00002000u)
#define DMTIMER_TCLR_CAPT_MODE_SHIFT   (0x0000000Du)
#define DMTIMER_TCLR_CAPT_MODE_SECOND   (0x1u)
#define DMTIMER_TCLR_CAPT_MODE_SINGLE   (0x0u)

#define DMTIMER_TCLR_CE   (0x00000040u)
#define DMTIMER_TCLR_CE_SHIFT   (0x00000006u)
#define DMTIMER_TCLR_CE_DISABLE   (0x0u)
#define DMTIMER_TCLR_CE_ENABLE   (0x1u)

#define DMTIMER_TCLR_GPO_CFG   (0x00004000u)
#define DMTIMER_TCLR_GPO_CFG_SHIFT   (0x0000000Eu)
#define DMTIMER_TCLR_GPO_CFG_DRIVE1   (0x1u)
#define DMTIMER_TCLR_GPO_CFG_DRIVE0   (0x0u)

#define DMTIMER_TCLR_PRE   (0x00000020u)
#define DMTIMER_TCLR_PRE_SHIFT   (0x00000005u)
#define DMTIMER_TCLR_PRE_DISABLE   (0x0u)
#define DMTIMER_TCLR_PRE_ENABLE   (0x1u)

#define DMTIMER_TCLR_PT   (0x00001000u)
#define DMTIMER_TCLR_PT_SHIFT   (0x0000000Cu)
#define DMTIMER_TCLR_PT_PULSE   (0x0u)
#define DMTIMER_TCLR_PT_TOGGLE   (0x1u)

#define DMTIMER_TCLR_PTV   (0x0000001Cu)
#define DMTIMER_TCLR_PTV_SHIFT   (0x00000002u)

#define DMTIMER_TCLR_SCPWM   (0x00000080u)
#define DMTIMER_TCLR_SCPWM_SHIFT   (0x00000007u)
#define DMTIMER_TCLR_SCPWM_CLEAR   (0x0u)
#define DMTIMER_TCLR_SCPWM_SET   (0x1u)

#define DMTIMER_TCLR_ST   (0x00000001u)
#define DMTIMER_TCLR_ST_SHIFT   (0x00000000u)
#define DMTIMER_TCLR_ST_START   (0x1u)
#define DMTIMER_TCLR_ST_STOP   (0x0u)

#define DMTIMER_TCLR_TCM   (0x00000300u)
#define DMTIMER_TCLR_TCM_SHIFT   (0x00000008u)
#define DMTIMER_TCLR_TCM_BOTH   (0x3u)
#define DMTIMER_TCLR_TCM_HIGHLOW   (0x2u)
#define DMTIMER_TCLR_TCM_LOWHIGH   (0x1u)
#define DMTIMER_TCLR_TCM_NOCAPTURE   (0x0u)

#define DMTIMER_TCLR_TRG   (0x00000C00u)
#define DMTIMER_TCLR_TRG_SHIFT   (0x0000000Au)
#define DMTIMER_TCLR_TRG_NOTRIGGER   (0x0u)
#define DMTIMER_TCLR_TRG_OVERFLOW   (0x1u)
#define DMTIMER_TCLR_TRG_OVERFLOWANDMATCH   (0x2u)


/* TCRR */
#define DMTIMER_TCRR_TIMER_COUNTER   (0xFFFFFFFFu)
#define DMTIMER_TCRR_TIMER_COUNTER_SHIFT   (0x00000000u)


/* TLDR */
#define DMTIMER_TLDR_LOAD_VALUE   (0xFFFFFFFFu)
#define DMTIMER_TLDR_LOAD_VALUE_SHIFT   (0x00000000u)


/* TTGR */
#define DMTIMER_TTGR_TTGR_VALUE   (0xFFFFFFFFu)
#define DMTIMER_TTGR_TTGR_VALUE_SHIFT   (0x00000000u)


/* TWPS */
#define DMTIMER_TWPS_W_PEND_TCLR   (0x00000001u)
#define DMTIMER_TWPS_W_PEND_TCLR_SHIFT   (0x00000000u)
#define DMTIMER_TWPS_W_PEND_TCLR_NONE   (0x0u)
#define DMTIMER_TWPS_W_PEND_TCLR_PENDING   (0x1u)

#define DMTIMER_TWPS_W_PEND_TCRR   (0x00000002u)
#define DMTIMER_TWPS_W_PEND_TCRR_SHIFT   (0x00000001u)
#define DMTIMER_TWPS_W_PEND_TCRR_NONE   (0x0u)
#define DMTIMER_TWPS_W_PEND_TCRR_PENDING   (0x1u)

#define DMTIMER_TWPS_W_PEND_TLDR   (0x00000004u)
#define DMTIMER_TWPS_W_PEND_TLDR_SHIFT   (0x00000002u)
#define DMTIMER_TWPS_W_PEND_TLDR_NONE   (0x0u)
#define DMTIMER_TWPS_W_PEND_TLDR_PENDING   (0x1u)

#define DMTIMER_TWPS_W_PEND_TMAR   (0x00000010u)
#define DMTIMER_TWPS_W_PEND_TMAR_SHIFT   (0x00000004u)
#define DMTIMER_TWPS_W_PEND_TMAR_NONE   (0x0u)
#define DMTIMER_TWPS_W_PEND_TMAR_PENDING   (0x1u)

#define DMTIMER_TWPS_W_PEND_TTGR   (0x00000008u)
#define DMTIMER_TWPS_W_PEND_TTGR_SHIFT   (0x00000003u)
#define DMTIMER_TWPS_W_PEND_TTGR_NONE   (0x0u)
#define DMTIMER_TWPS_W_PEND_TTGR_PENDING   (0x1u)


/* TMAR */
#define DMTIMER_TMAR_COMPARE_VALUE   (0xFFFFFFFFu)
#define DMTIMER_TMAR_COMPARE_VALUE_SHIFT   (0x00000000u)


/* TCAR1 */
#define DMTIMER_TCAR1_CAPTURED_VALUE   (0xFFFFFFFFu)
#define DMTIMER_TCAR1_CAPTURED_VALUE_SHIFT   (0x00000000u)


/* TSICR */
#define DMTIMER_TSICR_POSTED   (0x00000004u)
#define DMTIMER_TSICR_POSTED_SHIFT   (0x00000002u)
#define DMTIMER_TSICR_POSTED_ACTIVE   (0x1u)
#define DMTIMER_TSICR_POSTED_INACTIVE   (0x0u)

#define DMTIMER_TSICR_SFT   (0x00000002u)
#define DMTIMER_TSICR_SFT_SHIFT   (0x00000001u)
#define DMTIMER_TSICR_SFT_RESETDISABLE   (0x1u)
#define DMTIMER_TSICR_SFT_RESETENABLE   (0x0u)


/* TCAR2 */
#define DMTIMER_TCAR2_CAPTURED_VALUE   (0xFFFFFFFFu)
#define DMTIMER_TCAR2_CAPTURED_VALUE_SHIFT   (0x00000000u)



/******************************************************************************
**                      INTERNAL MACRO DEFINITIONS
*******************************************************************************/
#define TIMER_INITIAL_COUNT             (0xFFFFA23Fu)
//#define TIMER_RLD_COUNT                 (0xFF000000u)

/* The Input clock is selected as 24MHz. So for 1ms set the count to 0x5DC0. 
 *If the input clock is changed to different source this value has to be updated 
 *accordingly.	
*/
#define TIMER_1MS_COUNT                 (0x5DC0u) 
#define TIMER_OVERFLOW                  (0xFFFFFFFFu)

#define DELAY_USE_INTERRUPTS            1

/*****************************************************************************/
/*
** Values that can be passed to DMTimerPreScalerClkEnable as ptv so as to derive
** Pre-Scalar clock from timer clock.
*/
/* Value used to divide timer clock by 2 */
#define DMTIMER_PRESCALER_CLK_DIV_BY_2      ((0 << DMTIMER_TCLR_PTV_SHIFT) | \
                                              DMTIMER_TCLR_PRE)

/* Value used to divide timer clock by 4 */
#define DMTIMER_PRESCALER_CLK_DIV_BY_4	    ((1 << DMTIMER_TCLR_PTV_SHIFT) | \
                                              DMTIMER_TCLR_PRE)

/* Value used to divide timer clock by 8 */
#define DMTIMER_PRESCALER_CLK_DIV_BY_8	    ((2 << DMTIMER_TCLR_PTV_SHIFT) | \
                                              DMTIMER_TCLR_PRE)

/* Value used to divide timer clock by 16 */
#define DMTIMER_PRESCALER_CLK_DIV_BY_16	    ((3 << DMTIMER_TCLR_PTV_SHIFT) | \
                                              DMTIMER_TCLR_PRE)

/* Value used to divide timer clock by 32 */
#define DMTIMER_PRESCALER_CLK_DIV_BY_32	    ((4 << DMTIMER_TCLR_PTV_SHIFT) | \
                                              DMTIMER_TCLR_PRE)

/* Value used to divide timer clock by 64 */
#define DMTIMER_PRESCALER_CLK_DIV_BY_64	    ((5 << DMTIMER_TCLR_PTV_SHIFT) | \
                                              DMTIMER_TCLR_PRE)

/* Value used to divide timer clock by 128 */
#define DMTIMER_PRESCALER_CLK_DIV_BY_128    ((6 << DMTIMER_TCLR_PTV_SHIFT) | \
                                              DMTIMER_TCLR_PRE)

/* Value used to divide timer clock by 256 */
#define DMTIMER_PRESCALER_CLK_DIV_BY_256    ((7 << DMTIMER_TCLR_PTV_SHIFT) | \
                                              DMTIMER_TCLR_PRE)

/******************************************************************************/
/*
** Values that can be passed to DMTimerModeConfigure as timerMode.
*/
/* Value used to enable the timer in one-shot and compare mode */
#define DMTIMER_ONESHOT_CMP_ENABLE          (DMTIMER_TCLR_CE)

/* Value used to enable the timer only in one-shot mode */
#define DMTIMER_ONESHOT_NOCMP_ENABLE        (0x0000000)

/* Value used to enable the timer in auto-reload and compare mode */
#define DMTIMER_AUTORLD_CMP_ENABLE          (DMTIMER_TCLR_AR | DMTIMER_TCLR_CE)

/* Value used to enable the timer only in auto-reload mode */
#define DMTIMER_AUTORLD_NOCMP_ENABLE        (DMTIMER_TCLR_AR)

/******************************************************************************/
/*
** Values that can be passed to DMTimerGPOConfigure as gpoCfg.
*/
/* Value used to drive 0 on PORGPOCFG pin */
#define DMTIMER_GPO_CFG_0		    (DMTIMER_TCLR_GPO_CFG_DRIVE0)

/* Value used to drive 1 on PORGPOCFG pin */
#define DMTIMER_GPO_CFG_1		    (DMTIMER_TCLR_GPO_CFG_DRIVE1 << \
					     DMTIMER_TCLR_GPO_CFG_SHIFT)

/******************************************************************************/
/*
** Values that can be passed to DMTimerIntStatusClear/DMTimerIntRawStatusSet/
** as intFlags. Also these values can be used while checking the status got from 
** DMTimerIntRawStatusGet/DMTimerIntStatusGet.
** Any combination is also followed.
** Example- (DMTIMER_INT_TCAR_IT_FLAG | DMTIMER_INT_OVF_IT_FLAG)
*/
/* Value used for capture event of DMTimer */
#define DMTIMER_INT_TCAR_IT_FLAG             (DMTIMER_IRQSTATUS_RAW_TCAR_IT_FLAG)

/* Value used for overflow event of DMTimer */
#define DMTIMER_INT_OVF_IT_FLAG              (DMTIMER_IRQSTATUS_RAW_OVF_IT_FLAG) 

/* Value used for Match event of DMTimer */
#define DMTIMER_INT_MAT_IT_FLAG              (DMTIMER_IRQSTATUS_RAW_MAT_IT_FLAG)

/******************************************************************************/
/*
** Values that can be passed to DMTimerIntEnable/DMTimerIntDisable as intFlags.
** Also these values can be used while checking the status got from 
** DMTimerIntEnableGet.
** Any combination is also followed.
** Example- (DMTIMER_INT_TCAR_EN_FLAG | DMTIMER_INT_OVF_EN_FLAG)
*/
/* Value used for capture event of DMTimer */
#define DMTIMER_INT_TCAR_EN_FLAG             (DMTIMER_IRQENABLE_SET_TCAR_EN_FLAG)

/* Value used for overflow event of DMTimer */
#define DMTIMER_INT_OVF_EN_FLAG              (DMTIMER_IRQENABLE_SET_OVF_EN_FLAG)

/* Value used for Match event of DMTimer */
#define DMTIMER_INT_MAT_EN_FLAG              (DMTIMER_IRQENABLE_SET_MAT_EN_FLAG)

/******************************************************************************/
/*
** Values that can be passed to DMTimerResetConfigure as rstOption.
*/
/* Value used to enable software reset for DMTimer */
#define DMTIMER_SFT_RESET_ENABLE             (DMTIMER_TSICR_SFT_RESETENABLE)

/* Value used to disable software reset for DMTimer */
#define DMTIMER_SFT_RESET_DISABLE            (DMTIMER_TSICR_SFT)

/******************************************************************************/
/*
** Values that can be used while checking the status received from 
** DMTimerIsResetDone.
*/
/* Value used to check whether reset is done */
#define DMTIMER_IS_RESET_DONE                (DMTIMER_TIOCP_CFG_SOFTRESET_DONE)

/* Value used to check whether reset is ongoing */
#define DMTIMER_IS_RESET_ONGOING             (DMTIMER_TIOCP_CFG_SOFTRESET_ONGOING)

/******************************************************************************/
/*
** Values that can be passed to DMTimerPostedModeConfig as postMode.
*/
/* Value used to enable the posted mode of operation */
#define DMTIMER_POSTED                       (DMTIMER_TSICR_POSTED)

/* Value used to disable the posted mode of operation */
#define DMTIMER_NONPOSTED                    (DMTIMER_TSICR_POSTED_INACTIVE)

/******************************************************************************/
/*
** Values that can be used while checking status received from
** DMTimerWritePostedStatusGet API.
*/
/* Value used to check the write posted condition for TMAR register */
#define DMTIMER_WRITE_POST_TMAR              (DMTIMER_TWPS_W_PEND_TMAR)

/* Value used to check the write posted condition for TTGR register */
#define DMTIMER_WRITE_POST_TTGR              (DMTIMER_TWPS_W_PEND_TTGR)

/* Value used to check the write posted condition for TLDR register */
#define DMTIMER_WRITE_POST_TLDR              (DMTIMER_TWPS_W_PEND_TLDR)

/* Value used to check the write posted condition for TCRR register */
#define DMTIMER_WRITE_POST_TCRR              (DMTIMER_TWPS_W_PEND_TCRR)

/* Value used to check the write posted condition for TCLR register */
#define DMTIMER_WRITE_POST_TCLR              (DMTIMER_TWPS_W_PEND_TCLR)

extern bool flag_timer;

void DMTimerCounterSet(unsigned int , unsigned int );
unsigned int DMTimerCounterGet(unsigned int ); 
void DMTimerEnable(unsigned int );
void DMTimerDisable(unsigned int );
void DMTimerSetUp(void );
void delay(unsigned int );

#endif //TIMER_H_
