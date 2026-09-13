// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Amlal El Mahrouss (amlal@nekernel.org)
// Licensed under the Apache License, Version 2.0 (see LICENSE file)
// Official repository: https://github.com/ne-app-eu/src

#include <stdbool.h>
#include <Ne/Drivers/DDS.h>

static struct ddk_guard_type* kIrqGuard =
    (struct ddk_guard_type*) kalloc(sizeof(struct ddk_guard_type));

/// @todo AMLALE: Lock specific IRQs.

DDK_EXTERN void ddk_lock_irq(void) {
  MUST_PASS(kIrqGuard);
  if (!kIrqGuard) return;

  ddk_guard_function(kIrqGuard);

#ifdef __NEOSKRNL__
  ke_call_dispatch("IrqLockInterrupts", 1, kIrqGuard, sizeof(struct ddk_guard_type));
#else
  ke_call_dispatch("RtlIrqLockInterrupts", 1, kIrqGuard, sizeof(struct ddk_guard_type));
#endif
}

/// @brief unlock interrupts, in other words resume them.
DDK_EXTERN void ddk_unlock_irq(void) {
  MUST_PASS(kIrqGuard);
  if (!kIrqGuard) return;

#ifdef __NEOSKRNL__
  ke_call_dispatch("IrqUnlockInterrupts", 1, kIrqGuard, sizeof(struct ddk_guard_type));
#else
  ke_call_dispatch("RtlIrqUnlockInterrupts", 1, kIrqGuard, sizeof(struct ddk_guard_type));
#endif
}
