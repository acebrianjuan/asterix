/*
 *  Copyright (c) 2013 Croatia Control Ltd. (www.crocontrol.hr)
 *
 *  This file is part of Asterix.
 *
 *  Asterix is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Asterix is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Asterix.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * AUTHORS: Damir Salantic, Croatia Control Ltd.
 *
 */

#ifndef DATAITEMFORMATVARIABLE_H_
#define DATAITEMFORMATVARIABLE_H_

#include "DataItemFormat.h"
#include "DataItemFormatFixed.h"

class DataItemFormatVariable : public DataItemFormat
{
public:
  DataItemFormatVariable();
  virtual
  ~DataItemFormatVariable();

  std::list<DataItemFormatFixed*> m_lParts;

  long getLength(const unsigned char* pData);
  void addBits(DataItemBits* pBits);
  bool get(std::string& strResult, std::string& strHeader, const unsigned int formatType, unsigned char* pData, long nLength); // appends value description to strResult
  bool getValue(unsigned char* pData, long nLength, long& value, const char* pstrBitsShortName, const char* pstrBitsName = NULL);
  bool getValue(unsigned char* pData, long nLength, unsigned long& value, const char* pstrBitsShortName, const char* pstrBitsName = NULL);
  bool getValue(unsigned char* pData, long nLength, std::string& value, const char* pstrBitsShortName, const char* pstrBitsName = NULL);
#if defined(WIRESHARK_WRAPPER) || defined(ETHEREAL_WRAPPER)
  fulliautomatix_definitions* getWiresharkDefinitions();
  fulliautomatix_data* getData(unsigned char* pData, long len, int byteoffset);
#endif
};

#endif /* DATAITEMFORMATVARIABLE_H_ */
