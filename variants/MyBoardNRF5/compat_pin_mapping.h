/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

#ifndef MY_ARDUINO_CORE_NRF5
const uint32_t g_ADigitalPinMap[] = {
#if PINS_COUNT>(0u)
  g_APinDescription[0].ulPin | (g_APinDescription[0].ulPort << 5)
#endif
#if PINS_COUNT>(1u)
  ,g_APinDescription[1].ulPin | (g_APinDescription[1].ulPort << 5)
#endif
#if PINS_COUNT>(2u)
  ,g_APinDescription[2].ulPin | (g_APinDescription[2].ulPort << 5)
#endif
#if PINS_COUNT>(3u)
  ,g_APinDescription[3].ulPin | (g_APinDescription[3].ulPort << 5)
#endif
#if PINS_COUNT>(4u)
  ,g_APinDescription[4].ulPin | (g_APinDescription[4].ulPort << 5)
#endif
#if PINS_COUNT>(5u)
  ,g_APinDescription[5].ulPin | (g_APinDescription[5].ulPort << 5)
#endif
#if PINS_COUNT>(6u)
  ,g_APinDescription[6].ulPin | (g_APinDescription[6].ulPort << 5)
#endif
#if PINS_COUNT>(7u)
  ,g_APinDescription[7].ulPin | (g_APinDescription[7].ulPort << 5)
#endif
#if PINS_COUNT>(8u)
  ,g_APinDescription[8].ulPin | (g_APinDescription[8].ulPort << 5)
#endif
#if PINS_COUNT>(9u)
  ,g_APinDescription[9].ulPin | (g_APinDescription[9].ulPort << 5)
#endif
#if PINS_COUNT>(10u)
  ,g_APinDescription[10].ulPin | (g_APinDescription[10].ulPort << 5)
#endif
#if PINS_COUNT>(11u)
  ,g_APinDescription[11].ulPin | (g_APinDescription[11].ulPort << 5)
#endif
#if PINS_COUNT>(12u)
  ,g_APinDescription[12].ulPin | (g_APinDescription[12].ulPort << 5)
#endif
#if PINS_COUNT>(13u)
  ,g_APinDescription[13].ulPin | (g_APinDescription[13].ulPort << 5)
#endif
#if PINS_COUNT>(14u)
  ,g_APinDescription[14].ulPin | (g_APinDescription[14].ulPort << 5)
#endif
#if PINS_COUNT>(15u)
  ,g_APinDescription[15].ulPin | (g_APinDescription[15].ulPort << 5)
#endif
#if PINS_COUNT>(16u)
  ,g_APinDescription[16].ulPin | (g_APinDescription[16].ulPort << 5)
#endif
#if PINS_COUNT>(17u)
  ,g_APinDescription[17].ulPin | (g_APinDescription[17].ulPort << 5)
#endif
#if PINS_COUNT>(18u)
  ,g_APinDescription[18].ulPin | (g_APinDescription[18].ulPort << 5)
#endif
#if PINS_COUNT>(19u)
  ,g_APinDescription[19].ulPin | (g_APinDescription[19].ulPort << 5)
#endif
#if PINS_COUNT>(20u)
  ,g_APinDescription[20].ulPin | (g_APinDescription[20].ulPort << 5)
#endif
#if PINS_COUNT>(21u)
  ,g_APinDescription[21].ulPin | (g_APinDescription[21].ulPort << 5)
#endif
#if PINS_COUNT>(22u)
  ,g_APinDescription[22].ulPin | (g_APinDescription[22].ulPort << 5)
#endif
#if PINS_COUNT>(23u)
  ,g_APinDescription[23].ulPin | (g_APinDescription[23].ulPort << 5)
#endif
#if PINS_COUNT>(24u)
  ,g_APinDescription[24].ulPin | (g_APinDescription[24].ulPort << 5)
#endif
#if PINS_COUNT>(25u)
  ,g_APinDescription[25].ulPin | (g_APinDescription[25].ulPort << 5)
#endif
#if PINS_COUNT>(26u)
  ,g_APinDescription[26].ulPin | (g_APinDescription[26].ulPort << 5)
#endif
#if PINS_COUNT>(27u)
  ,g_APinDescription[27].ulPin | (g_APinDescription[27].ulPort << 5)
#endif
#if PINS_COUNT>(28u)
  ,g_APinDescription[28].ulPin | (g_APinDescription[28].ulPort << 5)
#endif
#if PINS_COUNT>(29u)
  ,g_APinDescription[29].ulPin | (g_APinDescription[29].ulPort << 5)
#endif
#if PINS_COUNT>(30u)
  ,g_APinDescription[30].ulPin | (g_APinDescription[30].ulPort << 5)
#endif
#if PINS_COUNT>(31u)
  ,g_APinDescription[31].ulPin | (g_APinDescription[31].ulPort << 5)
#endif
#if PINS_COUNT>(32u)
  ,g_APinDescription[32].ulPin | (g_APinDescription[32].ulPort << 5)
#endif
#if PINS_COUNT>(33u)
  ,g_APinDescription[33].ulPin | (g_APinDescription[33].ulPort << 5)
#endif
#if PINS_COUNT>(34u)
  ,g_APinDescription[34].ulPin | (g_APinDescription[34].ulPort << 5)
#endif
#if PINS_COUNT>(35u)
  ,g_APinDescription[35].ulPin | (g_APinDescription[35].ulPort << 5)
#endif
#if PINS_COUNT>(36u)
  ,g_APinDescription[36].ulPin | (g_APinDescription[36].ulPort << 5)
#endif
#if PINS_COUNT>(37u)
  ,g_APinDescription[37].ulPin | (g_APinDescription[37].ulPort << 5)
#endif
#if PINS_COUNT>(38u)
  ,g_APinDescription[38].ulPin | (g_APinDescription[38].ulPort << 5)
#endif
#if PINS_COUNT>(39u)
  ,g_APinDescription[39].ulPin | (g_APinDescription[39].ulPort << 5)
#endif
#if PINS_COUNT>(40u)
  ,g_APinDescription[40].ulPin | (g_APinDescription[40].ulPort << 5)
#endif
#if PINS_COUNT>(41u)
  ,g_APinDescription[41].ulPin | (g_APinDescription[41].ulPort << 5)
#endif
#if PINS_COUNT>(42u)
  ,g_APinDescription[42].ulPin | (g_APinDescription[42].ulPort << 5)
#endif
#if PINS_COUNT>(43u)
  ,g_APinDescription[43].ulPin | (g_APinDescription[43].ulPort << 5)
#endif
#if PINS_COUNT>(44u)
  ,g_APinDescription[44].ulPin | (g_APinDescription[44].ulPort << 5)
#endif
#if PINS_COUNT>(45u)
  ,g_APinDescription[45].ulPin | (g_APinDescription[45].ulPort << 5)
#endif
#if PINS_COUNT>(46u)
  ,g_APinDescription[46].ulPin | (g_APinDescription[46].ulPort << 5)
#endif
#if PINS_COUNT>(47u)
  ,g_APinDescription[47].ulPin | (g_APinDescription[47].ulPort << 5)
#endif
#if PINS_COUNT>(48u)
  ,g_APinDescription[48].ulPin | (g_APinDescription[48].ulPort << 5)
#endif
#if PINS_COUNT>(49u)
  ,g_APinDescription[49].ulPin | (g_APinDescription[49].ulPort << 5)
#endif
#if PINS_COUNT>(50u)
  ,g_APinDescription[50].ulPin | (g_APinDescription[50].ulPort << 5)
#endif
#if PINS_COUNT>(51u)
  ,g_APinDescription[51].ulPin | (g_APinDescription[51].ulPort << 5)
#endif
#if PINS_COUNT>(52u)
  ,g_APinDescription[52].ulPin | (g_APinDescription[52].ulPort << 5)
#endif
#if PINS_COUNT>(53u)
  ,g_APinDescription[53].ulPin | (g_APinDescription[53].ulPort << 5)
#endif
#if PINS_COUNT>(54u)
  ,g_APinDescription[54].ulPin | (g_APinDescription[54].ulPort << 5)
#endif
#if PINS_COUNT>(55u)
  ,g_APinDescription[55].ulPin | (g_APinDescription[55].ulPort << 5)
#endif
#if PINS_COUNT>(56u)
  ,g_APinDescription[56].ulPin | (g_APinDescription[56].ulPort << 5)
#endif
#if PINS_COUNT>(57u)
  ,g_APinDescription[57].ulPin | (g_APinDescription[57].ulPort << 5)
#endif
#if PINS_COUNT>(58u)
  ,g_APinDescription[58].ulPin | (g_APinDescription[58].ulPort << 5)
#endif
#if PINS_COUNT>(59u)
  ,g_APinDescription[59].ulPin | (g_APinDescription[59].ulPort << 5)
#endif
#if PINS_COUNT>(60u)
  ,g_APinDescription[60].ulPin | (g_APinDescription[60].ulPort << 5)
#endif
#if PINS_COUNT>(61u)
  ,g_APinDescription[61].ulPin | (g_APinDescription[61].ulPort << 5)
#endif
#if PINS_COUNT>(62u)
  ,g_APinDescription[62].ulPin | (g_APinDescription[62].ulPort << 5)
#endif
#if PINS_COUNT>(63u)
  ,g_APinDescription[63].ulPin | (g_APinDescription[63].ulPort << 5)
#endif
};
#endif
