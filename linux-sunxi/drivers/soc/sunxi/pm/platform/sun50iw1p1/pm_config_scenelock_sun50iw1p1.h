/*
 * drivers/soc/sunxi/pm/platform/sun50iw1p1/pm_config_scenelock_sun50iw1p1.h
 * (C) Copyright 2010-2016
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Yanggq <yanggq@allwinnertech.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#ifndef _SCENELOCK_EXSTANDBY_CFG_SUN50IW1P1_H
#define _SCENELOCK_EXSTANDBY_CFG_SUN50IW1P1_H

#include <linux/power/axp_depend.h>

struct scene_extended_standby_t extended_standby[] = {
	{
		.scene_type		    = SCENE_SUPER_STANDBY,
		.name			    = "super_standby",
		.soc_pwr_dep.id             = SUPER_STANDBY_FLAG,
		/*
		mean dram, cpus,dram_pll,vcc_pl, vcc_io, vcc_ldoin is on.
		note: vcc_pm is marked on, just for cross-platform reason.
		at a83: with the sys_mask's help, we know we do not need care about vcc_pm state.
		Because disable AVCC/VCC_PLL will lead to pll stable time extended, and enable AVCC/VCC_PLL only
		increase power consumption 60uA. So keeping AVCC/VCC_PLL enable when standby.
		*/
		/*mean care about cpua, dram, sys, cpus, dram_pll, vdd_adc, vcc_pl, vcc_io, vcc_cpvdd, vcc_ldoin, vcc_pll */
		.soc_pwr_dep.soc_pwr_dm_state.state	= BITMAP(VCC_DRAM_BIT) |\
							  BITMAP(VDD_CPUS_BIT) |\
							  BITMAP(VCC_LPDDR_BIT) |\
							  BITMAP(VCC_PL_BIT) |\
							  BITMAP(VCC_PLL_BIT),
		/*mean: donot need care about the voltage.*/
		.soc_pwr_dep.soc_pwr_dm_state.volt[0]      = 0x0,
		/* mean all osc is off.*/
		.soc_pwr_dep.cpux_clk_state.osc_en         = 0x0,
		/*mean pll5 is shutdowned & open by dram driver.*/
		.soc_pwr_dep.cpux_clk_state.init_pll_dis   = BITMAP(PM_PLL_DRAM),
		.soc_pwr_dep.cpux_clk_state.exit_pll_en    = 0x0,
		.soc_pwr_dep.cpux_clk_state.pll_change     = 0x0,
		.soc_pwr_dep.cpux_clk_state.bus_change     = 0x0,
		.soc_pwr_dep.soc_dram_state.selfresh_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.hold_flag     = 0x1,
		/*for pf port: set the io to disable state.;*/
		.soc_pwr_dep.soc_io_state.io_state[0] = {0x01c208b4,
							 0x00f0f0ff,
							 0x00707077},
		.soc_pwr_dep.soc_io_state.io_state[1] = {0x01c208b4,
							 0x000f0f00,
							 0x00070700},

	},
	{
		.scene_type     = SCENE_NORMAL_STANDBY,
		.name           = "normal_standby",
		.soc_pwr_dep.id = NORMAL_STANDBY_FLAG,
		.soc_pwr_dep.soc_pwr_dm_state.state = BITMAP(VCC_DRAM_BIT)
						| BITMAP(VDD_CPUS_BIT)
						| BITMAP(VCC_LPDDR_BIT)
						| BITMAP(VCC_PL_BIT)
						| BITMAP(VDD_SYS_BIT)
						| BITMAP(VDD_CPUA_BIT)
						| BITMAP(VCC_IO_BIT)
						| BITMAP(VCC_PLL_BIT),
		.soc_pwr_dep.soc_pwr_dm_state.volt[0]     = 0x0,
		.soc_pwr_dep.cpux_clk_state.osc_en        = 0x0,
		.soc_pwr_dep.cpux_clk_state.init_pll_dis = BITMAP(PM_PLL_DRAM),
		.soc_pwr_dep.cpux_clk_state.exit_pll_en   = 0x0,
		.soc_pwr_dep.cpux_clk_state.pll_change    = 0x0,
		.soc_pwr_dep.cpux_clk_state.bus_change    = 0x0,
		.soc_pwr_dep.soc_dram_state.selfresh_flag = 0x1,
		.soc_pwr_dep.soc_io_state.hold_flag       = 0x1,
		/*
		 * set pl5 and pl6 output low
		 * otherwise current will leak from vcc-pl to eldo1
		 */
		.soc_pwr_dep.soc_io_state.io_state[0] = {0x01c208b4,
							 0x00f0f0ff,
							 0x00707077},
		.soc_pwr_dep.soc_io_state.io_state[1] = {0x01c208b4,
							 0x000f0f00,
							 0x00070700},
	},
	{
		.scene_type	= SCENE_TALKING_STANDBY,
		.name		= "talking_standby",
		.soc_pwr_dep.id             = TALKING_STANDBY_FLAG,
		/*mean dram, cpus,dram_pll,vcc_pl, vcc_io, vcc_ldoin is on.
		note: vcc_pm is marked on, just for cross-platform reason.
		at a83: with the sys_mask's help, we know we do not need care about vcc_pm state.*/
		.soc_pwr_dep.soc_pwr_dm_state.state	   = BITMAP(VCC_DRAM_BIT) | BITMAP(VDD_CPUS_BIT) |\
							     BITMAP(VCC_LPDDR_BIT) | BITMAP(VCC_PL_BIT),
		/*mean: donot need care about the voltage.*/
		/* mean all osc is off.*/
		.soc_pwr_dep.soc_pwr_dm_state.volt[0]      = 0x0,
		.soc_pwr_dep.cpux_clk_state.osc_en         = 0x0,
		/*mean pll5 is shutdowned & open by dram driver.*/
		.soc_pwr_dep.cpux_clk_state.init_pll_dis   = BITMAP(PM_PLL_DRAM),
		.soc_pwr_dep.cpux_clk_state.exit_pll_en    = 0x0,
		.soc_pwr_dep.cpux_clk_state.pll_change     = 0x0,
		.soc_pwr_dep.cpux_clk_state.bus_change     = 0x0,
		.soc_pwr_dep.soc_dram_state.selfresh_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.hold_flag     = 0x1,
		/*for pf port: set the io to disable state.;*/
		.soc_pwr_dep.soc_io_state.io_state[0]     = {0x01c208b4, 0x00f0f0ff, 0x00707077},
		.soc_pwr_dep.soc_io_state.io_state[1]     = {0x01c208b4, 0x000f0f00, 0x00070700},

	},

	{
		.scene_type	= SCENE_USB_STANDBY,
		.name		= "usb_standby",
		.soc_pwr_dep.id  		= USB_STANDBY_FLAG,
		.soc_pwr_dep.soc_pwr_dm_state.state	   = BITMAP(VCC_DRAM_BIT) | BITMAP(VDD_CPUS_BIT) |\
							     BITMAP(VCC_LPDDR_BIT) | BITMAP(VCC_PL_BIT) |\
							     BITMAP(VDD_SYS_BIT) | BITMAP(VCC_IO_BIT) |\
							     BITMAP(VCC_PLL_BIT),

		.soc_pwr_dep.soc_pwr_dm_state.volt[0]           = 0x0,
		.soc_pwr_dep.soc_pwr_dm_state.volt[VDD_SYS_BIT] = 980,
		.soc_pwr_dep.soc_pwr_dm_state.volt[VCC_PLL_BIT] = 2500,
		.soc_pwr_dep.soc_pwr_dm_state.volt[VCC_IO_BIT]  = 3000,
		.soc_pwr_dep.cpux_clk_state.osc_en         = BITMAP(OSC_LOSC_BIT),
		.soc_pwr_dep.cpux_clk_state.init_pll_dis   = BITMAP(PM_PLL_DRAM),
		.soc_pwr_dep.cpux_clk_state.exit_pll_en    = 0x0,
		.soc_pwr_dep.cpux_clk_state.pll_change     = 0x0,
		.soc_pwr_dep.cpux_clk_state.pll_factor[PM_PLL_PERIPH] = {
		    .factor1 = 1,
		    .factor2 = 1,
		    .factor3 = 0,
		},
		.soc_pwr_dep.cpux_clk_state.bus_change     = BITMAP(BUS_AHB1) | BITMAP(BUS_AHB2) | BITMAP(BUS_APB1) | BITMAP(BUS_APB2),
		.soc_pwr_dep.cpux_clk_state.bus_factor[BUS_AHB1]     = {
		    .src = CLK_SRC_LOSC,
		    .pre_div = 0,
		    .div_ratio = 0,
		},
		.soc_pwr_dep.cpux_clk_state.bus_factor[BUS_AHB2]     = {
		    .src = CLK_SRC_AHB1,
		    .pre_div = 0,
		    .div_ratio = 0,
		},
		.soc_pwr_dep.cpux_clk_state.bus_factor[BUS_APB1]     = {
		    .src = CLK_SRC_AHB1,
		    .pre_div = 0,
		    .div_ratio = 0,
		},
		.soc_pwr_dep.cpux_clk_state.bus_factor[BUS_APB2]     = {
		    .src = CLK_SRC_LOSC,
		    .n = 0,
		    .m = 0,
		},
		.soc_pwr_dep.soc_dram_state.selfresh_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.hold_flag     = 0x0,
		.soc_pwr_dep.soc_io_state.io_state[0]     = {0x01c208b4, 0x00f0f0ff, 0x00707077},
		.soc_pwr_dep.soc_io_state.io_state[1]     = {0x01c208b4, 0x000f0f00, 0x00070700},
	},
	{
		.scene_type	= SCENE_USB_OHCI_STANDBY,
		.name		= "usb_ohci_standby",
		.soc_pwr_dep.id  		= USB_OHCI_STANDBY_FLAG,
		.soc_pwr_dep.soc_pwr_dm_state.state	   = BITMAP(VCC_DRAM_BIT) | BITMAP(VDD_CPUS_BIT) |\
							     BITMAP(VCC_LPDDR_BIT) | BITMAP(VCC_PL_BIT) | \
							     BITMAP(VDD_SYS_BIT) | BITMAP(VCC_IO_BIT),
		.soc_pwr_dep.soc_pwr_dm_state.volt[0]      = 0x0,
		.soc_pwr_dep.cpux_clk_state.osc_en         = BITMAP(OSC_LOSC_BIT) | BITMAP(OSC_HOSC_BIT) | BITMAP(OSC_LDO1_BIT) | BITMAP(OSC_LDO0_BIT),
		.soc_pwr_dep.cpux_clk_state.init_pll_dis   = BITMAP(PM_PLL_DRAM) | BITMAP(PM_PLL_PERIPH),
		.soc_pwr_dep.cpux_clk_state.exit_pll_en    = 0x0,
		.soc_pwr_dep.cpux_clk_state.pll_change     = BITMAP(PM_PLL_PERIPH),
		.soc_pwr_dep.cpux_clk_state.pll_factor[PM_PLL_PERIPH] = {
		    .factor1 = 0,
		    .factor2 = 0,
		    .factor3 = 0,
		},
		.soc_pwr_dep.cpux_clk_state.bus_change     = BITMAP(BUS_AHB1) | BITMAP(BUS_AHB2),
		.soc_pwr_dep.cpux_clk_state.bus_factor[BUS_AHB1]     = {
		    .src = CLK_SRC_LOSC,
		    .pre_div = 0,
		    .div_ratio = 0,
		},
		.soc_pwr_dep.cpux_clk_state.bus_factor[BUS_AHB2]     = {
		    .src = CLK_SRC_AHB1,
		    .pre_div = 0,
		    .div_ratio = 0,
		},
		.soc_pwr_dep.soc_dram_state.selfresh_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.hold_flag     = 0x0,
		.soc_pwr_dep.soc_io_state.io_state[0]     = {0x01c208b4, 0x00f0f0ff, 0x00707077},
		.soc_pwr_dep.soc_io_state.io_state[1]     = {0x01c208b4, 0x000f0f00, 0x00070700},
	},
	{
		.scene_type	= SCENE_USB_EHCI_STANDBY,
		.name		= "usb_ehci_standby",
		.soc_pwr_dep.id  		= USB_EHCI_STANDBY_FLAG,
		.soc_pwr_dep.soc_pwr_dm_state.state	   = BITMAP(VCC_DRAM_BIT) | BITMAP(VDD_CPUS_BIT) |\
							     BITMAP(VCC_LPDDR_BIT) | BITMAP(VCC_PL_BIT) | \
							     BITMAP(VDD_SYS_BIT) | BITMAP(VCC_IO_BIT),
		.soc_pwr_dep.soc_pwr_dm_state.volt[0]      = 0x0,
		.soc_pwr_dep.cpux_clk_state.osc_en         = BITMAP(OSC_LOSC_BIT),
		.soc_pwr_dep.cpux_clk_state.init_pll_dis   = BITMAP(PM_PLL_DRAM),
		.soc_pwr_dep.cpux_clk_state.exit_pll_en    = 0x0,
		.soc_pwr_dep.cpux_clk_state.pll_change     = 0x0,
		.soc_pwr_dep.cpux_clk_state.bus_change     = BITMAP(BUS_AHB1) | BITMAP(BUS_AHB2),
		.soc_pwr_dep.cpux_clk_state.bus_factor[BUS_AHB1]     = {
		    .src = CLK_SRC_LOSC,
		    .pre_div = 0,
		    .div_ratio = 0,
		},
		.soc_pwr_dep.cpux_clk_state.bus_factor[BUS_AHB2]     = {
		    .src = CLK_SRC_AHB1,
		    .pre_div = 0,
		    .div_ratio = 0,
		},
		.soc_pwr_dep.soc_dram_state.selfresh_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.hold_flag     = 0x0,
		.soc_pwr_dep.soc_io_state.io_state[0]     = {0x01c208b4, 0x00f0f0ff, 0x00707077},
		.soc_pwr_dep.soc_io_state.io_state[1]     = {0x01c208b4, 0x000f0f00, 0x00070700},
	},
	{
		.scene_type	= SCENE_MP3_STANDBY,
		.name		= "mp3_standby",
		.soc_pwr_dep.id  		= MP3_STANDBY_FLAG,
	},
	{
		.scene_type	= SCENE_BOOT_FAST,
		.name		= "boot_fast",
		.soc_pwr_dep.id  		= BOOT_FAST_STANDBY_FLAG,
	},
	{
		.scene_type		    = SCENE_GPIO_HOLD_STANDBY,
		.name			    = "gpio_hold_standby",
		.soc_pwr_dep.id             = GPIO_HOLD_STANDBY_FLAG,
		.soc_pwr_dep.soc_pwr_dm_state.state	   = BITMAP(VCC_DRAM_BIT) | BITMAP(VDD_CPUS_BIT) |\
							     BITMAP(VCC_LPDDR_BIT) | BITMAP(VCC_PL_BIT) |\
							     BITMAP(VDD_SYS_BIT) | BITMAP(VCC_IO_BIT),
		.soc_pwr_dep.soc_pwr_dm_state.volt[0]      = 0x0,
		.soc_pwr_dep.cpux_clk_state.osc_en         = 0x0,
		.soc_pwr_dep.cpux_clk_state.init_pll_dis   = BITMAP(PM_PLL_DRAM),
		.soc_pwr_dep.cpux_clk_state.exit_pll_en    = 0x0,
		.soc_pwr_dep.cpux_clk_state.pll_change     = 0x0,
		.soc_pwr_dep.cpux_clk_state.bus_change     = 0x0,
		.soc_pwr_dep.soc_dram_state.selfresh_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.hold_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.io_state[0]     = {0x01c208b4, 0x00f0f0ff, 0x00707077},
		.soc_pwr_dep.soc_io_state.io_state[1]     = {0x01c208b4, 0x000f0f00, 0x00070700},

	},
	{
		.scene_type		    = SCENE_GPIO_STANDBY,
		.name			    = "gpio_standby",
		.soc_pwr_dep.id             = GPIO_STANDBY_FLAG,
		.soc_pwr_dep.soc_pwr_dm_state.state	   = BITMAP(VCC_DRAM_BIT) | BITMAP(VDD_CPUS_BIT) |\
							     BITMAP(VCC_LPDDR_BIT) | BITMAP(VCC_PL_BIT) |\
							     BITMAP(VDD_SYS_BIT) | BITMAP(VCC_IO_BIT),
		.soc_pwr_dep.soc_pwr_dm_state.volt[0]      = 0x0,
		.soc_pwr_dep.cpux_clk_state.osc_en         = BITMAP(OSC_LOSC_BIT),
		.soc_pwr_dep.cpux_clk_state.init_pll_dis   = BITMAP(PM_PLL_DRAM),
		.soc_pwr_dep.cpux_clk_state.exit_pll_en    = 0x0,
		.soc_pwr_dep.cpux_clk_state.pll_change     = 0x0,
		.soc_pwr_dep.cpux_clk_state.bus_change     = BITMAP(BUS_AHB1),
		.soc_pwr_dep.cpux_clk_state.bus_factor[BUS_AHB1]     = {
		    .src = CLK_SRC_LOSC,
		    .pre_div = 0,
		    .div_ratio = 0,
		},
		.soc_pwr_dep.soc_dram_state.selfresh_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.hold_flag     = 0x0,
		.soc_pwr_dep.soc_io_state.io_state[0]     = {0x01c208b4, 0x00f0f0ff, 0x00707077},
		.soc_pwr_dep.soc_io_state.io_state[1]     = {0x01c208b4, 0x000f0f00, 0x00070700},

	},

	{
		.scene_type	= SCENE_MISC_STANDBY,
		.name		= "misc_standby",
		.soc_pwr_dep.id = MISC_STANDBY_FLAG,
		.soc_pwr_dep.soc_pwr_dm_state.state	   = BITMAP(VCC_DRAM_BIT) | BITMAP(VDD_CPUS_BIT) |\
							     BITMAP(VCC_PL_BIT) | \
							     BITMAP(VCC_IO_BIT), 0x0644,
		.soc_pwr_dep.soc_pwr_dm_state.volt[0]      = 0x0,
		.soc_pwr_dep.cpux_clk_state.osc_en         = 0x0,
		.soc_pwr_dep.cpux_clk_state.init_pll_dis   = (~(0x20)),
		.soc_pwr_dep.cpux_clk_state.exit_pll_en    = 0x0,
		.soc_pwr_dep.cpux_clk_state.pll_change     = 0x0,
		.soc_pwr_dep.cpux_clk_state.bus_change     = 0x0,
		.soc_pwr_dep.soc_dram_state.selfresh_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.hold_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.io_state[0]     = {0x01c208b4, 0x00f0f0ff, 0x00707077},
		.soc_pwr_dep.soc_io_state.io_state[1]     = {0x01c208b4, 0x000f0f00, 0x00070700},
	},
	{
		.scene_type	= SCENE_MISC1_STANDBY,
		.name		= "misc1_standby",
		.soc_pwr_dep.id = MISC1_STANDBY_FLAG,
		.soc_pwr_dep.soc_pwr_dm_state.state	   = BITMAP(VCC_DRAM_BIT) | BITMAP(VDD_CPUS_BIT) |\
							     BITMAP(VCC_PL_BIT),
		.soc_pwr_dep.soc_pwr_dm_state.volt[0]      = 0x0,
		.soc_pwr_dep.cpux_clk_state.osc_en         = 0x0,
		.soc_pwr_dep.cpux_clk_state.init_pll_dis   = (~(0x20)),
		.soc_pwr_dep.cpux_clk_state.exit_pll_en    = 0x0,
		.soc_pwr_dep.cpux_clk_state.pll_change     = 0x0,
		.soc_pwr_dep.cpux_clk_state.bus_change     = 0x0,
		.soc_pwr_dep.soc_dram_state.selfresh_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.hold_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.io_state[0]     = {0x01c208b4, 0x00f0f0ff, 0x00707077},
		.soc_pwr_dep.soc_io_state.io_state[1]     = {0x01c208b4, 0x000f0f00, 0x00070700},
	},
	{
		.scene_type		    = SCENE_DYNAMIC_STANDBY,
		.name			    = "dynamic_standby",
		.soc_pwr_dep.id             = DYNAMIC_STANDBY_FLAG,
		.soc_pwr_dep.soc_pwr_dm_state.state	   = BITMAP(VCC_DRAM_BIT) | BITMAP(VDD_CPUS_BIT) |\
							     BITMAP(VCC_LPDDR_BIT) | BITMAP(VCC_PL_BIT),
		.soc_pwr_dep.soc_pwr_dm_state.volt[0]      = 0x0,
		.soc_pwr_dep.cpux_clk_state.osc_en         = 0x0,
		.soc_pwr_dep.cpux_clk_state.init_pll_dis   = (BITMAP(PM_PLL_DRAM)),
		.soc_pwr_dep.cpux_clk_state.exit_pll_en    = 0x0,
		.soc_pwr_dep.cpux_clk_state.pll_change     = 0x0,
		.soc_pwr_dep.cpux_clk_state.bus_change     = 0x0,
		.soc_pwr_dep.soc_dram_state.selfresh_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.hold_flag     = 0x1,
		.soc_pwr_dep.soc_io_state.io_state[0]     = {0x01c208b4, 0x00f0f0ff, 0x00707077},
		.soc_pwr_dep.soc_io_state.io_state[1]     = {0x01c208b4, 0x000f0f00, 0x00070700},
	},
};

#endif /* _SCENELOCK_EXSTANDBY_CFG_SUN50IW1P1_H */
