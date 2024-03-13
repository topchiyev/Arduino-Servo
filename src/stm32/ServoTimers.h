/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010, LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

 /*
 * Arduino srl - www.arduino.org
 * 2017 Feb 23: Edited by Francesco Alessi (alfran) - francesco@arduino.org
 */
#ifndef _SERVO_H_
#define _SERVO_H_

// #include "types.h"
#include "timer.h"

#include "wiring.h"             /* hack for IDE compile */

/*
 * Note on Arduino compatibility:
 *
 * In the Arduino implementation, PWM is done "by hand" in the sense
 * that timer channels are hijacked in groups and an ISR is set which
 * toggles Servo::attach()ed pins using digitalWrite().
 *
 * While this scheme allows any pin to drive a servo, it chews up
 * cycles and complicates the programmer's notion of when a particular
 * timer channel will be in use.
 *
 * This implementation only allows Servo instances to attach() to pins
 * that already have a timer channel associated with them, and just
 * uses analogWrite() to drive the wave.
 *
 * This introduces an incompatibility: while the Arduino
 * implementation of attach() returns the affected channel on success
 * and 0 on failure, this one returns true on success and false on
 * failure.
 *
 * RC Servos expect a pulse every 20 ms. Since periods are set for
 * entire timers, rather than individual channels, attach()ing a Servo
 * to a pin can interfere with other pins associated with the same
 * timer. As always, your board's pin map is your friend.
 */

// Pin number of unattached pins
#define NOT_ATTACHED                    (-1)

#define _Nbr_16timers 14 // Number of STM32F469 Timers
#define SERVOS_PER_TIMER 4 // Number of timer channels


// Default min/max pulse widths (in microseconds) and angles (in
// degrees). Values chosen for Arduino compatibility. These values
// are part of the public API; DO NOT CHANGE THEM.
#define MIN_ANGLE               0
#define MAX_ANGLE             180

#define MIN_PULSE_WIDTH       544     // the shortest pulse sent to a servo
#define MAX_PULSE_WIDTH      2400     // the longest pulse sent to a servo


#endif  /* _SERVO_H_ */
