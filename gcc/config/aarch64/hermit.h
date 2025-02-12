/* Machine description for AArch64 architecture.
   Copyright (C) 2009-2016 Free Software Foundation, Inc.
   Contributed by ARM Ltd.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

/* Support for HermitCore builds.  */
#ifndef GCC_AARCH64_HERMIT_H
#define GCC_AARCH64_HERMIT_H

#if TARGET_FIX_ERR_A53_835769_DEFAULT
#define CA53_ERR_835769_SPEC \
  " %{!mno-fix-cortex-a53-835769:--fix-cortex-a53-835769}"
#else
#define CA53_ERR_835769_SPEC \
  " %{mfix-cortex-a53-835769:--fix-cortex-a53-835769}"
#endif

#if TARGET_FIX_ERR_A53_843419_DEFAULT
#define CA53_ERR_843419_SPEC \
  " %{!mno-fix-cortex-a53-843419:--fix-cortex-a53-843419}"
#else
#define CA53_ERR_843419_SPEC \
  " %{mfix-cortex-a53-843419:--fix-cortex-a53-843419}"
#endif

#ifndef LINK_SPEC
#define LINK_SPEC "%{h*}			\
   %{static:-Bstatic}				\
   %{shared:-shared}				\
   %{symbolic:-Bsymbolic}			\
   %{!static:%{rdynamic:-export-dynamic}}	\
   %{mbig-endian:-EB} %{mlittle-endian:-EL} -X	\
  -maarch64hermit%{mabi=ilp32*:32}%{mbig-endian:b}" \
  CA53_ERR_835769_SPEC \
  CA53_ERR_843419_SPEC
#endif

#undef LIB_SPEC
#define LIB_SPEC "%{pthread:-lpthread} --whole-archive -lc --no-whole-archive -lg"

#endif /* GCC_AARCH64_HERMIT_H */
