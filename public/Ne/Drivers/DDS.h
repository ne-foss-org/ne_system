// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://git.nekernel.org/src

#ifndef _NE_DDK_DDS_H_
#define _NE_DDK_DDS_H_

#include <Ne/Drivers/Detail/Config.h>

#ifndef _DDS
#define _DDS (202605L)
#endif

#ifndef DDK_UNLOCK_IRQ
#define DDK_UNLOCK_IRQ ATTRIBUTE(cleanup(ddk_unlock_irq))
#endif

DDK_EXTERN void ddk_lock_irq(void);
DDK_EXTERN void ddk_unlock_irq(void);

#endif // _NE_DDK_DDS_H_
