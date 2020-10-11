// SPDX-License-Identifier: GPL-2.0+
/*
 * Freescale i.MX28 RAM init
 *
 * Copyright (C) 2011 Marek Vasut <marek.vasut@gmail.com>
 * on behalf of DENX Software Engineering GmbH
 */

#include <common.h>
#include <config.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <linux/compiler.h>

#include "mxs_init.h"

__weak uint32_t mxs_dram_vals[] = {
/*
 * i.MX28 DDR2 at 200MHz
 */
#if defined(CONFIG_MX28)
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 000 - 003
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 004 - 007
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 008 - 011
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 012 - 015
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 016 - 019
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 020 - 023
	0x00000000, 0x00000000, 0x00010101, 0x01010101, // 024 - 027
	0x000f0f01, 0x0f02010a, 0x00000000, 0x00000101, // 028 - 031
	0x00000100, 0x00000100, 0x01000000, 0x00000002, // 032 - 035
	0x01010000, 0x06040201, 0x06000001, 0x0a000000, // 036 - 039
	0x02009c40, 0x0002030b, 0x0036b008, 0x030e0550, // 040 - 043
	0x02030002, 0x00170017, 0x00000000, 0x00000000, // 044 - 047
	0x00013200, 0xffff0303, 0x00013200, 0xffff0303, // 048 - 051
	0x00013200, 0xffff0303, 0x00013200, 0xffff0303, // 052 - 055
	0x00000003, 0x00000000, 0x00000000, 0x00000000, // 056 - 059
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 060 - 063
	0x00000000, 0x00000000, 0x00000305, 0x01000f02, // 064 - 067
	0x00000000, 0x00000200, 0x00020007, 0xf3004a27, // 068 - 071
	0xf3004a27, 0x00000000, 0x00000000, 0x07000310, // 072 - 075
	0x07000310, 0x00000000, 0x00000000, 0x00800004, // 076 - 079
	0x00000000, 0x00000000, 0x01000000, 0x01020408, // 080 - 083
	0x08040201, 0x000f1133, 0x00000000, 0x00001f08, // 084 - 087
	0x00001f08, 0x00000000, 0x00000000, 0x00001f01, // 088 - 091
	0x00001f01, 0x00000000, 0x00000000, 0x00000000, // 092 - 095
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 096 - 099
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 100 - 103
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 104 - 107
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 108 - 111
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 112 - 115
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 116 - 119
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 120 - 123
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 124 - 127
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 128 - 131
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 132 - 135
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 136 - 139
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 140 - 143
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 144 - 147
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 148 - 151
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 152 - 155
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 156 - 159
	0x00000000, 0x00000000, 0x00000000, 0x00010301, // 160 - 163
	0x00000002, 0x00000000, 0x00000000, 0x00000000, // 164 - 167
	0x00000000, 0x00000000, 0x00000000, 0x01010000, // 168 - 171
	0x01000100, 0x03030000, 0x00020303, 0x01010202, // 172 - 175
	0x00000000, 0x01030101, 0x21002101, 0x00030500, // 176 - 179
	0x03050305, 0x00320032, 0x00320032, 0x00000000, // 180 - 183
	0x00000000, 0x00000000, 0x00000000, 0x00000000, // 184 - 187
	0x00000000, 0xffffffff                          // 188 - 189

/*
 * i.MX23 DDR at 133MHz
 */
#elif defined(CONFIG_MX23)
	0x01010001, 0x00010100, 0x01000101, 0x00000001,
	0x00000101, 0x00000000, 0x00010000, 0x01000001,
	0x00000000, 0x00000001, 0x07000200, 0x00070202,
	0x02020000, 0x04040a01, 0x00000201, 0x02040000,
	0x02000000, 0x19000f08, 0x0d0d0000, 0x02021313,
	0x02061521, 0x0000000a, 0x00080008, 0x00200020,
	0x00200020, 0x00200020, 0x000003f7, 0x00000000,
	0x00000000, 0x00000020, 0x00000020, 0x00c80000,
	0x000a23cd, 0x000000c8, 0x00006665, 0x00000000,
	0x00000101, 0x00040001, 0x00000000, 0x00000000,
	0x00010000
#else
#error Unsupported memory initialization
#endif
};

__weak void mxs_adjust_memory_params(uint32_t *dram_vals)
{
	debug("SPL: Using default SDRAM parameters\n");
}

#ifdef CONFIG_MX28
static void initialize_dram_values(void)
{
	int i;

	debug("SPL: Setting mx28 board specific SDRAM parameters\n");
	mxs_adjust_memory_params(mxs_dram_vals);

	debug("SPL: Applying SDRAM parameters\n");
	for (i = 0; i < ARRAY_SIZE(mxs_dram_vals); i++)
		writel(mxs_dram_vals[i], MXS_DRAM_BASE + (4 * i));
}
#else
static void initialize_dram_values(void)
{
	int i;

	debug("SPL: Setting mx23 board specific SDRAM parameters\n");
	mxs_adjust_memory_params(mxs_dram_vals);

	/*
	 * HW_DRAM_CTL27, HW_DRAM_CTL28 and HW_DRAM_CTL35 are not initialized as
	 * per FSL bootlets code.
	 *
	 * mx23 Reference Manual marks HW_DRAM_CTL27 and HW_DRAM_CTL28 as
	 * "reserved".
	 * HW_DRAM_CTL8 is setup as the last element.
	 * So skip the initialization of these HW_DRAM_CTL registers.
	 */
	debug("SPL: Applying SDRAM parameters\n");
	for (i = 0; i < ARRAY_SIZE(mxs_dram_vals); i++) {
		if (i == 8 || i == 27 || i == 28 || i == 35)
			continue;
		writel(mxs_dram_vals[i], MXS_DRAM_BASE + (4 * i));
	}

	/*
	 * Enable tRAS lockout in HW_DRAM_CTL08 ; it must be the last
	 * element to be set
	 */
	writel((1 << 24), MXS_DRAM_BASE + (4 * 8));
}
#endif

static void mxs_mem_init_clock(void)
{
	struct mxs_clkctrl_regs *clkctrl_regs =
		(struct mxs_clkctrl_regs *)MXS_CLKCTRL_BASE;
#if defined(CONFIG_MX23)
	/* Fractional divider for ref_emi is 33 ; 480 * 18 / 33 = 266MHz */
	const unsigned char divider = 33;
#elif defined(CONFIG_MX28)
	/* Fractional divider for ref_emi is 21 ; 480 * 18 / 21 = 411MHz */
	const unsigned char divider = 21;
#endif

	debug("SPL: Initialising FRAC0\n");

	/* Gate EMI clock */
	writeb(CLKCTRL_FRAC_CLKGATE,
		&clkctrl_regs->hw_clkctrl_frac0_set[CLKCTRL_FRAC0_EMI]);

	/* Set fractional divider for ref_emi */
	writeb(CLKCTRL_FRAC_CLKGATE | (divider & CLKCTRL_FRAC_FRAC_MASK),
		&clkctrl_regs->hw_clkctrl_frac0[CLKCTRL_FRAC0_EMI]);

	/* Ungate EMI clock */
	writeb(CLKCTRL_FRAC_CLKGATE,
		&clkctrl_regs->hw_clkctrl_frac0_clr[CLKCTRL_FRAC0_EMI]);

	early_delay(11000);

	/* Set EMI clock divider for EMI clock to 411 / 2 = 205MHz */
	writel((2 << CLKCTRL_EMI_DIV_EMI_OFFSET) |
		(1 << CLKCTRL_EMI_DIV_XTAL_OFFSET),
		&clkctrl_regs->hw_clkctrl_emi);

	/* Unbypass EMI */
	writel(CLKCTRL_CLKSEQ_BYPASS_EMI,
		&clkctrl_regs->hw_clkctrl_clkseq_clr);

	early_delay(10000);
	debug("SPL: FRAC0 Initialised\n");
}

static void mxs_mem_setup_cpu_and_hbus(void)
{
	struct mxs_clkctrl_regs *clkctrl_regs =
		(struct mxs_clkctrl_regs *)MXS_CLKCTRL_BASE;

	debug("SPL: Setting CPU and HBUS clock frequencies\n");

	/* Set fractional divider for ref_cpu to 480 * 18 / 19 = 454MHz
	 * and ungate CPU clock */
	writeb(19 & CLKCTRL_FRAC_FRAC_MASK,
		(uint8_t *)&clkctrl_regs->hw_clkctrl_frac0[CLKCTRL_FRAC0_CPU]);

	/* Set CPU bypass */
	writel(CLKCTRL_CLKSEQ_BYPASS_CPU,
		&clkctrl_regs->hw_clkctrl_clkseq_set);

	/* HBUS = 151MHz */
	writel(CLKCTRL_HBUS_DIV_MASK, &clkctrl_regs->hw_clkctrl_hbus_set);
	writel(((~3) << CLKCTRL_HBUS_DIV_OFFSET) & CLKCTRL_HBUS_DIV_MASK,
		&clkctrl_regs->hw_clkctrl_hbus_clr);

	early_delay(10000);

	/* CPU clock divider = 1 */
	clrsetbits_le32(&clkctrl_regs->hw_clkctrl_cpu,
			CLKCTRL_CPU_DIV_CPU_MASK, 1);

	/* Disable CPU bypass */
	writel(CLKCTRL_CLKSEQ_BYPASS_CPU,
		&clkctrl_regs->hw_clkctrl_clkseq_clr);

	early_delay(15000);
}

static void mxs_mem_setup_vdda(void)
{
	struct mxs_power_regs *power_regs =
		(struct mxs_power_regs *)MXS_POWER_BASE;

	debug("SPL: Configuring VDDA\n");

	writel((0xc << POWER_VDDACTRL_TRG_OFFSET) |
		(0x7 << POWER_VDDACTRL_BO_OFFSET_OFFSET) |
		POWER_VDDACTRL_LINREG_OFFSET_1STEPS_BELOW,
		&power_regs->hw_power_vddactrl);
}

uint32_t mxs_mem_get_size(void)
{
	uint32_t sz, da;
	uint32_t *vt = (uint32_t *)0x20;
	/* The following is "subs pc, r14, #4", used as return from DABT. */
	const uint32_t data_abort_memdetect_handler = 0xe25ef004;

	/* Replace the DABT handler. */
	da = vt[4];
	vt[4] = data_abort_memdetect_handler;

	sz = get_ram_size((long *)PHYS_SDRAM_1, PHYS_SDRAM_1_SIZE);

	/* Restore the old DABT handler. */
	vt[4] = da;

	return sz;
}

#ifdef CONFIG_MX23
static void mx23_mem_setup_vddmem(void)
{
	struct mxs_power_regs *power_regs =
		(struct mxs_power_regs *)MXS_POWER_BASE;

	debug("SPL: Setting mx23 VDDMEM\n");

	/* We must wait before and after disabling the current limiter! */
	early_delay(10000);

	clrbits_le32(&power_regs->hw_power_vddmemctrl,
		POWER_VDDMEMCTRL_ENABLE_ILIMIT);

	early_delay(10000);

}

static void mx23_mem_init(void)
{
	debug("SPL: Initialising mx23 SDRAM Controller\n");

	/*
	 * Reset/ungate the EMI block. This is essential, otherwise the system
	 * suffers from memory instability. This thing is mx23 specific and is
	 * no longer present on mx28.
	 */
	mxs_reset_block((struct mxs_register_32 *)MXS_EMI_BASE);

	mx23_mem_setup_vddmem();

	/*
	 * Configure the DRAM registers
	 */

	/* Clear START and SREFRESH bit from DRAM_CTL8 */
	clrbits_le32(MXS_DRAM_BASE + 0x20, (1 << 16) | (1 << 8));

	initialize_dram_values();

	/* Set START bit in DRAM_CTL8 */
	setbits_le32(MXS_DRAM_BASE + 0x20, 1 << 16);

	clrbits_le32(MXS_DRAM_BASE + 0x40, 1 << 17);

	/* Wait for EMI_STAT bit DRAM_HALTED */
	for (;;) {
		if (!(readl(MXS_EMI_BASE + 0x10) & (1 << 1)))
			break;
		early_delay(1000);
	}

	/* Adjust EMI port priority. */
	clrsetbits_le32(0x80020000, 0x1f << 16, 0x2);
	early_delay(20000);

	setbits_le32(MXS_DRAM_BASE + 0x40, 1 << 19);
	setbits_le32(MXS_DRAM_BASE + 0x40, 1 << 11);
}
#endif

#ifdef CONFIG_MX28
static void mx28_mem_init(void)
{
	struct mxs_pinctrl_regs *pinctrl_regs =
		(struct mxs_pinctrl_regs *)MXS_PINCTRL_BASE;

	debug("SPL: Initialising mx28 SDRAM Controller\n");

	/* Set LPDDR mode */
	writel(PINCTRL_EMI_DS_CTRL_DDR_MODE_DDR2,
		&pinctrl_regs->hw_pinctrl_emi_ds_ctrl_clr);

	/*
	 * Configure the DRAM registers
	 */

	/* Clear START bit from DRAM_CTL16 */
	clrbits_le32(MXS_DRAM_BASE + 0x40, 1);

	initialize_dram_values();

	/* Clear SREFRESH bit from DRAM_CTL17 */
	clrbits_le32(MXS_DRAM_BASE + 0x44, 1);

	/* Set START bit in DRAM_CTL16 */
	setbits_le32(MXS_DRAM_BASE + 0x40, 1);

	/* Wait for bit 20 (DRAM init complete) in DRAM_CTL58 */
	while (!(readl(MXS_DRAM_BASE + 0xe8) & (1 << 20)))
		;
}
#endif

void mxs_mem_init(void)
{
	early_delay(11000);

	mxs_mem_init_clock();

	mxs_mem_setup_vdda();

#if defined(CONFIG_MX23)
	mx23_mem_init();
#elif defined(CONFIG_MX28)
	mx28_mem_init();
#endif

	early_delay(10000);

	mxs_mem_setup_cpu_and_hbus();
}
