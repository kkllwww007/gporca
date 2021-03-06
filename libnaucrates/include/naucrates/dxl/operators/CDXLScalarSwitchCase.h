//---------------------------------------------------------------------------
//	Greenplum Database
//	Copyright (C) 2012 EMC Corp.
//
//	@filename:
//		CDXLScalarSwitchCase.h
//
//	@doc:
//
//		Class for representing a single DXL switch case
//---------------------------------------------------------------------------

#ifndef GPDXL_CDXLScalarSwitchCase_H
#define GPDXL_CDXLScalarSwitchCase_H

#include "gpos/base.h"
#include "naucrates/dxl/operators/CDXLScalar.h"
#include "naucrates/md/IMDId.h"

namespace gpdxl
{
	using namespace gpos;
	using namespace gpmd;

	//---------------------------------------------------------------------------
	//	@class:
	//		CDXLScalarSwitchCase
	//
	//	@doc:
	//		Class for representing DXL Switch Case
	//
	//---------------------------------------------------------------------------
	class CDXLScalarSwitchCase : public CDXLScalar
	{
		private:
			// private copy ctor
			CDXLScalarSwitchCase(const CDXLScalarSwitchCase&);

		public:

			// ctor
			explicit
			CDXLScalarSwitchCase(IMemoryPool *pmp);

			//dtor
			virtual
			~CDXLScalarSwitchCase()
			{}

			// name of the operator
			virtual
			const CWStringConst *PstrOpName() const;

			// DXL Operator ID
			virtual
			Edxlopid Edxlop() const;

			// serialize operator in DXL format
			virtual
			void SerializeToDXL(CXMLSerializer *pxmlser, const CDXLNode *pdxln) const;

			// conversion function
			static
			CDXLScalarSwitchCase *PdxlopConvert
				(
				CDXLOperator *pdxlop
				)
			{
				GPOS_ASSERT(NULL != pdxlop);
				GPOS_ASSERT(EdxlopScalarSwitchCase == pdxlop->Edxlop());

				return dynamic_cast<CDXLScalarSwitchCase*>(pdxlop);
			}

			// does the operator return a boolean result
			virtual
			BOOL FBoolean
					(
					CMDAccessor *//pmda
					)
					const
			{
				GPOS_ASSERT(!"Invalid function call for a container operator");
				return false;
			}

#ifdef GPOS_DEBUG
			// checks whether the operator has valid structure, i.e. number and
			// types of child nodes
			void AssertValid(const CDXLNode *pdxln, BOOL fValidateChildren) const;
#endif // GPOS_DEBUG
	};
}
#endif // !GPDXL_CDXLScalarSwitchCase_H

// EOF
