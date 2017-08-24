// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "C:\\Program Files (x86)\\New River Kinematics\\SpatialAnalyzer 2016.06.03_15061\\SpatialAnalyzerSDK.exe" no_namespace
// CSpatialAnalyzerSDK wrapper class
#pragma once

class CSpatialAnalyzerSDK : public COleDispatchDriver
{
public:
	CSpatialAnalyzerSDK() {} // Calls COleDispatchDriver default constructor
	CSpatialAnalyzerSDK(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSpatialAnalyzerSDK(const CSpatialAnalyzerSDK& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// ISpatialAnalyzerSDK methods
public:
	BOOL Connect(LPCTSTR ipAddress)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ipAddress);
		return result;
	}
	void SetStep(LPCTSTR stepName)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, stepName);
	}
	BOOL ExecuteStep()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL SetPointNameArg(LPCTSTR argName, LPCTSTR collectionName, LPCTSTR groupName, LPCTSTR targetName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName, groupName, targetName);
		return result;
	}
	BOOL SetVectorArg(LPCTSTR argName, double XValue, double yValue, double zValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_R8 VTS_R8 VTS_R8;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, XValue, yValue, zValue);
		return result;
	}
	BOOL SetCollectionObjectNameArg(LPCTSTR argName, LPCTSTR collectionName, LPCTSTR objectName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName, objectName);
		return result;
	}
	BOOL SetDoubleArg(LPCTSTR argName, double value)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_R8;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, value);
		return result;
	}
	BOOL GetDoubleArg(LPCTSTR argName, double * value)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PR8;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, value);
		return result;
	}
	BOOL SetIntegerArg(LPCTSTR argName, long value)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, value);
		return result;
	}
	BOOL GetIntegerArg(LPCTSTR argName, long * value)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PI4;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, value);
		return result;
	}
	BOOL GetBoolArg(LPCTSTR argName, BOOL * value)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBOOL;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, value);
		return result;
	}
	BOOL SetBoolArg(LPCTSTR argName, BOOL value)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, value);
		return result;
	}
	BOOL SetStringArg(LPCTSTR argName, LPCTSTR value)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, value);
		return result;
	}
	BOOL GetStringArg(LPCTSTR argName, BSTR * value)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, value);
		return result;
	}
	BOOL GetPointNameArg(LPCTSTR argName, BSTR * collectionName, BSTR * groupName, BSTR * targetName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PBSTR VTS_PBSTR;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName, groupName, targetName);
		return result;
	}
	BOOL GetVectorArg(LPCTSTR argName, double * XValue, double * yValue, double * zValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PR8 VTS_PR8 VTS_PR8;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, XValue, yValue, zValue);
		return result;
	}
	BOOL GetCollectionObjectNameArg(LPCTSTR argName, BSTR * collectionName, BSTR * objectName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PBSTR;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName, objectName);
		return result;
	}
	BOOL GetMPStepResult(long * resultCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_PI4;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, resultCode);
		return result;
	}
	BOOL GetMPStepMessages(VARIANT * vArray)
	{
		BOOL result;
		static BYTE parms[] = VTS_PVARIANT;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, vArray);
		return result;
	}
	BOOL SetObjectNameArg(LPCTSTR argName, LPCTSTR objectName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, objectName);
		return result;
	}
	BOOL GetObjectNameArg(LPCTSTR argName, BSTR * objectName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, objectName);
		return result;
	}
	BOOL SetTransformArg(LPCTSTR argName, VARIANT * transform)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, transform);
		return result;
	}
	BOOL GetTransformArg(LPCTSTR argName, VARIANT * transform)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, transform);
		return result;
	}
	BOOL SetInstIdArg(LPCTSTR argName, long instId)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, instId);
		return result;
	}
	BOOL GetInstIdArg(LPCTSTR argName, long * instId)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PI4;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, instId);
		return result;
	}
	BOOL SetColInstIdArg(LPCTSTR argName, LPCTSTR collectionName, long instId)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName, instId);
		return result;
	}
	BOOL GetColInstIdArg(LPCTSTR argName, BSTR * collectionName, long * instId)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PI4;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName, instId);
		return result;
	}
	BOOL SetFilePathArg(LPCTSTR argName, LPCTSTR path, BOOL embeddedFile)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BOOL;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, path, embeddedFile);
		return result;
	}
	BOOL GetFilePathArg(LPCTSTR argName, BSTR * path, BOOL * embeddedFile)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PBOOL;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, path, embeddedFile);
		return result;
	}
	BOOL SetCollectionObjectNameRefListArg(LPCTSTR argName, VARIANT * objectNameList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, objectNameList);
		return result;
	}
	BOOL GetCollectionObjectNameRefListArg(LPCTSTR argName, VARIANT * objectNameList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, objectNameList);
		return result;
	}
	BOOL SetFrameNameArg(LPCTSTR argName, LPCTSTR frameName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, frameName);
		return result;
	}
	BOOL GetFrameNameArg(LPCTSTR argName, BSTR * frameName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, frameName);
		return result;
	}
	BOOL SetCollectionNameArg(LPCTSTR argName, LPCTSTR collectionName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName);
		return result;
	}
	BOOL GetCollectionNameArg(LPCTSTR argName, BSTR * collectionName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName);
		return result;
	}
	BOOL SetVectorGroupNameArg(LPCTSTR argName, LPCTSTR vectorGrpName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, vectorGrpName);
		return result;
	}
	BOOL GetVectorGroupNameArg(LPCTSTR argName, BSTR * vectorGrpName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, vectorGrpName);
		return result;
	}
	BOOL SetCloudNameArg(LPCTSTR argName, LPCTSTR cloudName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, cloudName);
		return result;
	}
	BOOL GetCloudNameArg(LPCTSTR argName, BSTR * cloudName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, cloudName);
		return result;
	}
	BOOL SetPerimeterNameArg(LPCTSTR argName, LPCTSTR perimeterName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, perimeterName);
		return result;
	}
	BOOL GetPerimeterNameArg(LPCTSTR argName, BSTR * perimeterName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, perimeterName);
		return result;
	}
	BOOL SetChartNameArg(LPCTSTR argName, LPCTSTR chartName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, chartName);
		return result;
	}
	BOOL GetChartNameArg(LPCTSTR argName, BSTR * chartName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x2c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, chartName);
		return result;
	}
	BOOL SetPointNameRefListArg(LPCTSTR argName, VARIANT * pointNameList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, pointNameList);
		return result;
	}
	BOOL GetPointNameRefListArg(LPCTSTR argName, VARIANT * pointNameList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, pointNameList);
		return result;
	}
	BOOL SetVectorNameRefListArg(LPCTSTR argName, VARIANT * vectorNameList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x2f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, vectorNameList);
		return result;
	}
	BOOL GetVectorNameRefListArg(LPCTSTR argName, VARIANT * vectorNameList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, vectorNameList);
		return result;
	}
	BOOL SetCollectionVectorGroupNameRefListArg(LPCTSTR argName, VARIANT * colVectorGrpNameList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x31, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, colVectorGrpNameList);
		return result;
	}
	BOOL GetCollectionVectorGroupNameRefListArg(LPCTSTR argName, VARIANT * colVectorGrpNameList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, colVectorGrpNameList);
		return result;
	}
	BOOL SetWorldTransformArg(LPCTSTR argName, VARIANT * transform, double scaleFactor)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT VTS_R8;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, transform, scaleFactor);
		return result;
	}
	BOOL GetWorldTransformArg(LPCTSTR argName, VARIANT * transform, double * scaleFactor)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT VTS_PR8;
		InvokeHelper(0x34, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, transform, scaleFactor);
		return result;
	}
	BOOL SetInstTypeNameArg(LPCTSTR argName, LPCTSTR instType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x35, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, instType);
		return result;
	}
	BOOL SetFontTypeArg(LPCTSTR argName, LPCTSTR fontName, unsigned char fontSize, unsigned char redColorVal, unsigned char greenColorVal, unsigned char blueColorVal)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_UI1 VTS_UI1 VTS_UI1 VTS_UI1;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, fontName, fontSize, redColorVal, greenColorVal, blueColorVal);
		return result;
	}
	BOOL SetGeometryTypeArg(LPCTSTR argName, LPCTSTR geometryType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, geometryType);
		return result;
	}
	BOOL SetSAInteractionModeArg(LPCTSTR argName, LPCTSTR saInteractionMode)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, saInteractionMode);
		return result;
	}
	BOOL SetMPInteractionModeArg(LPCTSTR argName, LPCTSTR mpInteractionMode)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, mpInteractionMode);
		return result;
	}
	BOOL SetMPDialogInteractionModeArg(LPCTSTR argName, LPCTSTR mpDialogInteractionMode)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x3a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, mpDialogInteractionMode);
		return result;
	}
	BOOL SetWorkbookAddressModeTypeArg(LPCTSTR argName, LPCTSTR workbookAddressMode)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x3b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, workbookAddressMode);
		return result;
	}
	BOOL SetMoveDirectionTypeArg(LPCTSTR argName, LPCTSTR moveDirection)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x3c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, moveDirection);
		return result;
	}
	BOOL SetWriteModeTypeArg(LPCTSTR argName, LPCTSTR writeMode)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x3d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, writeMode);
		return result;
	}
	BOOL SetProjectionOptionsArg(LPCTSTR argName, LPCTSTR projectionType, BOOL bIgnoreEdgeProjections, BOOL bOverrideTargetOffsets, double overrideTargetOffsetsValue, BOOL bAddExtraMaterialThickness, double extraMaterialThicknessValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BOOL VTS_BOOL VTS_R8 VTS_BOOL VTS_R8;
		InvokeHelper(0x3e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, projectionType, bIgnoreEdgeProjections, bOverrideTargetOffsets, overrideTargetOffsetsValue, bAddExtraMaterialThickness, extraMaterialThicknessValue);
		return result;
	}
	BOOL SetCollectionGroupNameRefListArg(LPCTSTR argName, VARIANT * groupNameList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x3f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, groupNameList);
		return result;
	}
	BOOL GetCollectionGroupNameRefListArg(LPCTSTR argName, VARIANT * colGroupNameList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x40, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, colGroupNameList);
		return result;
	}
	BOOL SetExportDataDelimeterTypeArg(LPCTSTR argName, LPCTSTR delimeterType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, delimeterType);
		return result;
	}
	BOOL SetExportTargetNameFormatArg(LPCTSTR argName, LPCTSTR targetNameFormat)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, targetNameFormat);
		return result;
	}
	BOOL SetCoordinateSystemTypeArg(LPCTSTR argName, LPCTSTR coordSystemType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, coordSystemType);
		return result;
	}
	BOOL SetAsciiFileFormatArg(LPCTSTR argName, LPCTSTR asciiFileFormat)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, asciiFileFormat);
		return result;
	}
	BOOL SetDistanceUnitsArg(LPCTSTR argName, LPCTSTR distanceUnits)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, distanceUnits);
		return result;
	}
	BOOL SetObjectTypeArg(LPCTSTR argName, LPCTSTR objectType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, objectType);
		return result;
	}
	BOOL SetViewNameArg(LPCTSTR argName, LPCTSTR viewName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, viewName);
		return result;
	}
	BOOL GetViewNameArg(LPCTSTR argName, BSTR * viewName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, viewName);
		return result;
	}
	BOOL SetColVectorGroupNameArg(LPCTSTR argName, LPCTSTR collectionName, LPCTSTR vectorGroupName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0x49, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName, vectorGroupName);
		return result;
	}
	BOOL GetColVectorGroupNameArg(LPCTSTR argName, BSTR * collectionName, BSTR * vectorGroupName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PBSTR;
		InvokeHelper(0x4a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName, vectorGroupName);
		return result;
	}
	BOOL SetColInstIdRefListArg(LPCTSTR argName, VARIANT * colInstIdList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x4b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, colInstIdList);
		return result;
	}
	BOOL GetColInstIdRefListArg(LPCTSTR argName, VARIANT * colInstIdList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x4c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, colInstIdList);
		return result;
	}
	BOOL SetFitDofOptionsArg(LPCTSTR argName, BOOL bAllowX, BOOL bAllowY, BOOL bAllowZ, BOOL bAllowRx, BOOL bAllowRy, BOOL bAllowRz, BOOL bRotateAboutCentroid)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL;
		InvokeHelper(0x4d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, bAllowX, bAllowY, bAllowZ, bAllowRx, bAllowRy, bAllowRz, bRotateAboutCentroid);
		return result;
	}
	BOOL SetReportOutputOptionsArg(LPCTSTR argName, LPCTSTR outputType, LPCTSTR pathOrEmbeddedName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0x4e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, outputType, pathOrEmbeddedName);
		return result;
	}
	BOOL GetReportOutputOptionsArg(LPCTSTR argName, BSTR * outputType, BSTR * pathOrEmbeddedName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PBSTR;
		InvokeHelper(0x4f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, outputType, pathOrEmbeddedName);
		return result;
	}
	BOOL SetStringRefListArg(LPCTSTR argName, VARIANT * stringList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x50, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, stringList);
		return result;
	}
	BOOL GetStringRefListArg(LPCTSTR argName, VARIANT * stringList)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PVARIANT;
		InvokeHelper(0x51, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, stringList);
		return result;
	}
	BOOL SetUserSummaryInfoFilesArg(LPCTSTR argName, LPCTSTR leftSummaryFilePath, LPCTSTR rightSummaryFilePath)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0x52, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, leftSummaryFilePath, rightSummaryFilePath);
		return result;
	}
	BOOL SetReportViewOptionsArg(LPCTSTR argName, LPCTSTR viewType, LPCTSTR collectionName, LPCTSTR calloutName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0x53, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, viewType, collectionName, calloutName);
		return result;
	}
	BOOL GetReportViewOptionsArg(LPCTSTR argName, BSTR * viewType, BSTR * collectionName, BSTR * calloutName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PBSTR VTS_PBSTR;
		InvokeHelper(0x54, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, viewType, collectionName, calloutName);
		return result;
	}
	BOOL SetAxisNameArg(LPCTSTR argName, LPCTSTR axisName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x55, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, axisName);
		return result;
	}
	BOOL SetReportTypeArg(LPCTSTR argName, LPCTSTR reportType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x56, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, reportType);
		return result;
	}
	BOOL SetBaseColorTypeArg(LPCTSTR argName, LPCTSTR baseColorType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x57, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, baseColorType);
		return result;
	}
	BOOL SetColorRangeMethodArg(LPCTSTR argName, LPCTSTR colorRangeMethod)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x58, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, colorRangeMethod);
		return result;
	}
	BOOL SetColorizationOptionsArg(LPCTSTR argName, LPCTSTR colorRangeMethod, LPCTSTR baseHighColor, LPCTSTR baseMidColor, LPCTSTR baseLowColor, BOOL bDrawTubes, BOOL bDrawArrowheads, BOOL bIndicateValues, double vectorMagnification, long vectorWidth, BOOL bDrawBlotches, double blotchSize, BOOL bShowOutOfToleranceOnly, BOOL bShowColorBarInView, BOOL bShowColorBarPercentages, BOOL bShowColorBarFractions, double highSaturationLimit, double lowSaturationLimit, double highTolerance, double lowTolerance)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BOOL VTS_BOOL VTS_BOOL VTS_R8 VTS_I4 VTS_BOOL VTS_R8 VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_R8 VTS_R8 VTS_R8 VTS_R8;
		InvokeHelper(0x59, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, colorRangeMethod, baseHighColor, baseMidColor, baseLowColor, bDrawTubes, bDrawArrowheads, bIndicateValues, vectorMagnification, vectorWidth, bDrawBlotches, blotchSize, bShowOutOfToleranceOnly, bShowColorBarInView, bShowColorBarPercentages, bShowColorBarFractions, highSaturationLimit, lowSaturationLimit, highTolerance, lowTolerance);
		return result;
	}
	BOOL SetColorArg(LPCTSTR argName, unsigned char redColorVal, unsigned char greenColorVal, unsigned char blueColorVal)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_UI1 VTS_UI1 VTS_UI1;
		InvokeHelper(0x5a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, redColorVal, greenColorVal, blueColorVal);
		return result;
	}
	BOOL ConnectEx(LPCTSTR ipAddress, long * statusCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PI4;
		InvokeHelper(0x5b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ipAddress, statusCode);
		return result;
	}
	BOOL SetWindowStateArg(LPCTSTR argName, LPCTSTR windowState)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x5c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, windowState);
		return result;
	}
	BOOL SetResultArg(LPCTSTR argName, LPCTSTR objectName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x5d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, objectName);
		return result;
	}
	BOOL GetResultArg(LPCTSTR argName, BSTR * objectName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR;
		InvokeHelper(0x5e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, objectName);
		return result;
	}
	BOOL SetRenderModeTypeArg(LPCTSTR argName, LPCTSTR renderModeType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x5f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, renderModeType);
		return result;
	}
	BOOL SetSurfDissectModeTypeArg(LPCTSTR argName, LPCTSTR dissectModeType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x60, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, dissectModeType);
		return result;
	}
	BOOL SetShowUsmnDialogTypeArg(LPCTSTR argName, LPCTSTR showType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x61, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, showType);
		return result;
	}
	BOOL SetReportPageSettingsArg(LPCTSTR argName, LPCTSTR pageOrientation)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x62, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, pageOrientation);
		return result;
	}
	BOOL SetPointDeltaReportOptionsArg(LPCTSTR argName, LPCTSTR coordSys, LPCTSTR detailsFormat, BOOL bShowA, BOOL bShowB, BOOL bShowDelta, BOOL bShowMag, BOOL bShowComponent1, BOOL bShowComponent2, BOOL bShowComponent3, BOOL bSortPointNames, BOOL bShowToleranceFields, BOOL bColorizeInToleranceFields)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL VTS_BOOL;
		InvokeHelper(0x63, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, coordSys, detailsFormat, bShowA, bShowB, bShowDelta, bShowMag, bShowComponent1, bShowComponent2, bShowComponent3, bSortPointNames, bShowToleranceFields, bColorizeInToleranceFields);
		return result;
	}
	BOOL SetDatasetTypeArg(LPCTSTR argName, LPCTSTR datasetType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, datasetType);
		return result;
	}
	BOOL SetChartTypeArg(LPCTSTR argName, LPCTSTR chartType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, chartType);
		return result;
	}
	BOOL SetColMachineIdArg(LPCTSTR argName, LPCTSTR collectionName, long machineId)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4;
		InvokeHelper(0x66, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName, machineId);
		return result;
	}
	BOOL GetColMachineIdArg(LPCTSTR argName, BSTR * collectionName, long * machineId)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PI4;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName, machineId);
		return result;
	}
	BOOL SetExportVectorNameFormatArg(LPCTSTR argName, LPCTSTR vectorNameFormat)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, vectorNameFormat);
		return result;
	}
	BOOL SetSystemStringArg(LPCTSTR argName, LPCTSTR systemStrName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, systemStrName);
		return result;
	}
	BOOL SetCloudThinningOptionsArg(LPCTSTR argName, LPCTSTR thinMode, long pointIncrement, long minNumPts, long maxNumPts)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, thinMode, pointIncrement, minNumPts, maxNumPts);
		return result;
	}
	BOOL SetToleranceScalarOptionsArg(LPCTSTR argName, BOOL bUseHigh, double highTol, BOOL bUseLow, double lowTol)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL VTS_R8 VTS_BOOL VTS_R8;
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, bUseHigh, highTol, bUseLow, lowTol);
		return result;
	}
	BOOL GetToleranceScalarOptionsArg(LPCTSTR argName, BOOL * bUseHigh, double * highTol, BOOL * bUseLow, double * lowTol)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBOOL VTS_PR8 VTS_PBOOL VTS_PR8;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, bUseHigh, highTol, bUseLow, lowTol);
		return result;
	}
	BOOL SetOffsetDirectionTypeArg(LPCTSTR argName, LPCTSTR offsetDirType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, offsetDirType);
		return result;
	}
	BOOL SetCollectionObjectNameArg2(LPCTSTR argName, LPCTSTR collectionName, LPCTSTR objectName, LPCTSTR objectType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, collectionName, objectName, objectType);
		return result;
	}
	BOOL SetDoubleArrayArg(LPCTSTR argName, long arraySize, VARIANT * arrayOut)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_PVARIANT;
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, arraySize, arrayOut);
		return result;
	}
	BOOL GetDoubleArrayArg(LPCTSTR argName, long * arraySize, VARIANT * arrayIn)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PI4 VTS_PVARIANT;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, arraySize, arrayIn);
		return result;
	}
	BOOL SetToleranceVectorOptionsArg(LPCTSTR argName, BOOL bUseHighX, double highTolX, BOOL bUseHighY, double highTolY, BOOL bUseHighZ, double highTolZ, BOOL bUseHighM, double highTolM, BOOL bUseLowX, double lowTolX, BOOL bUseLowY, double lowTolY, BOOL bUseLowZ, double lowTolZ, BOOL bUseLowM, double lowTolM)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BOOL VTS_R8 VTS_BOOL VTS_R8 VTS_BOOL VTS_R8 VTS_BOOL VTS_R8 VTS_BOOL VTS_R8 VTS_BOOL VTS_R8 VTS_BOOL VTS_R8 VTS_BOOL VTS_R8;
		InvokeHelper(0x71, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, bUseHighX, highTolX, bUseHighY, highTolY, bUseHighZ, highTolZ, bUseHighM, highTolM, bUseLowX, lowTolX, bUseLowY, lowTolY, bUseLowZ, lowTolZ, bUseLowM, lowTolM);
		return result;
	}
	BOOL GetToleranceVectorOptionsArg(LPCTSTR argName, BOOL * bUseHighX, double * highTolX, BOOL * bUseHighY, double * highTolY, BOOL * bUseHighZ, double * highTolZ, BOOL * bUseHighM, double * highTolM, BOOL * bUseLowX, double * lowTolX, BOOL * bUseLowY, double * lowTolY, BOOL * bUseLowZ, double * lowTolZ, BOOL * bUseLowM, double * lowTolM)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBOOL VTS_PR8 VTS_PBOOL VTS_PR8 VTS_PBOOL VTS_PR8 VTS_PBOOL VTS_PR8 VTS_PBOOL VTS_PR8 VTS_PBOOL VTS_PR8 VTS_PBOOL VTS_PR8 VTS_PBOOL VTS_PR8;
		InvokeHelper(0x72, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, bUseHighX, highTolX, bUseHighY, highTolY, bUseHighZ, highTolZ, bUseHighM, highTolM, bUseLowX, lowTolX, bUseLowY, lowTolY, bUseLowZ, lowTolZ, bUseLowM, lowTolM);
		return result;
	}
	BOOL SetAngularUnitsArg(LPCTSTR argName, LPCTSTR angularUnits)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x73, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, angularUnits);
		return result;
	}
	BOOL SetLogarithmicFunctionArg(LPCTSTR argName, LPCTSTR logarithmicFunction)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x74, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, logarithmicFunction);
		return result;
	}
	BOOL SetTrigFunctionArg(LPCTSTR argName, LPCTSTR trigFunction)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, trigFunction);
		return result;
	}
	BOOL SetMathOperationArg(LPCTSTR argName, LPCTSTR mathOperation)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x76, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, mathOperation);
		return result;
	}
	BOOL SetNumComparisonTypeArg(LPCTSTR argName, LPCTSTR compType)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR;
		InvokeHelper(0x77, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, argName, compType);
		return result;
	}

	// ISpatialAnalyzerSDK properties
public:

};
