Public Class SDK
    Private NrkSDK As SpatialAnalyzerSDK.SpatialAnalyzerSDK
    Private statusCode As Long

    Enum MPStatus
        SDKERROR = -1
        UNDONE = 0
        INPROGRESS = 1
        DONESUCCESS = 2
        DONEFATALERROR = 3
        DONEMINORERROR = 4
        CURRENTTASK = 5
    End Enum

    Public Sub New()
        NrkSDK = New SpatialAnalyzerSDK.SpatialAnalyzerSDK
    End Sub

    Public Sub conToSA()
        NrkSDK.ConnectEx("localhost", statusCode)
    End Sub

    'File Operations
    'MP Task Overview
    'MP Subroutines
    'View Control
    'Construction Operations 
    Public Sub CopyObject(ByRef colSrc As String, ByRef nmSrc As String, ByRef colDest As String, ByRef nmDest As String, Optional ByVal overwrite As Boolean = False)
        NrkSDK.SetStep("Copy Object")
        NrkSDK.SetCollectionObjectNameArg("Source Object", colSrc, nmSrc)
        NrkSDK.SetCollectionObjectNameArg("New Object Name", colDest, nmDest)
        NrkSDK.SetBoolArg("Overwrite if exists?", overwrite)
        NrkSDK.ExecuteStep()
    End Sub
    Public Sub RenamePoint(ByRef c1 As String, ByRef o1 As String, ByRef t1 As String, ByRef c2 As String, ByRef o2 As String, ByRef t2 As String, Optional ByVal overwrite As Boolean = False)
        NrkSDK.SetStep("Rename Point")
        NrkSDK.SetPointNameArg("Original Point Name", c1, o1, t1)
        NrkSDK.SetPointNameArg("New Point Name", c2, o2, t2)
        NrkSDK.SetBoolArg("Overwrite if exists?", overwrite)
        NrkSDK.ExecuteStep()
    End Sub
    'Collections
    Public Sub SetOrConstructDefaultCollection(ByRef col As String)
        NrkSDK.SetStep("Set (or construct) default collection")
        NrkSDK.SetCollectionNameArg("Collection Name", col)
        NrkSDK.ExecuteStep()
    End Sub
    Public Sub DeleteCollection(ByRef col As String)
        NrkSDK.SetStep("Delete Collection")
        NrkSDK.SetCollectionNameArg("Name of Collection to Delete", col)
        NrkSDK.ExecuteStep()
    End Sub
    Public Function GetActiveCollectionName() As String
        NrkSDK.SetStep("Get Active Collection Name")
        NrkSDK.ExecuteStep()
        Dim sValue As String = Nothing
        NrkSDK.GetCollectionNameArg("Currently Active Collection Name", sValue)
        Return sValue
    End Function
    'Points and Groups
    Public Sub ConstructPointFitToPoints(ByRef pntNmRefList() As String, ByRef col As String, ByRef grp As String, ByRef targ As String)
        Dim p(pntNmRefList.Length - 1)
        For idx As Integer = 0 To (pntNmRefList.Length - 1)
            p(idx) = pntNmRefList.ElementAt(idx)
        Next
        'Dim pp As Object = TryCast(p, Object)
        Dim vPointObjectList As Object = New System.Runtime.InteropServices.VariantWrapper(p)
        NrkSDK.SetStep("Construct Point (Fit to Points)")
        NrkSDK.SetPointNameRefListArg("Point Names", vPointObjectList)
        NrkSDK.SetPointNameArg("Resulting Point Name", col, grp, targ)
        NrkSDK.ExecuteStep()
    End Sub
    Public Sub ConstructAPointInWorkingCoordinates(ByRef c As String, ByRef g As String, ByRef t As String, ByVal x As Double, ByVal y As Double, ByVal z As Double)
        NrkSDK.SetStep("Construct a Point in Working Coordinates")
        NrkSDK.SetPointNameArg("Point Name", c, g, t)
        NrkSDK.SetVectorArg("Working Coordinates", x, y, z)
        NrkSDK.ExecuteStep()
    End Sub
    Public Sub ConstructAPointAtLineMidPoint(ByRef lcol As String, ByRef lname As String, ByRef ptCol As String, ByRef ptGrp As String, ByRef ptTarg As String)
        NrkSDK.SetStep("Construct a Point at line MidPoint")
        NrkSDK.SetCollectionObjectNameArg("Line Name", lcol, lname)
        NrkSDK.SetPointNameArg("Point Name", ptCol, ptGrp, ptTarg)
        NrkSDK.ExecuteStep()
    End Sub
    Public Sub ConstructAPointGroupFromPointNameRefList(ByRef ptNmRefList() As String, ByRef ptCol As String, ByRef ptGrp As String)
        Dim p(ptNmRefList.Length - 1)
        For idx As Integer = 0 To (ptNmRefList.Length - 1)
            p(idx) = ptNmRefList.ElementAt(idx)
        Next
        'Dim pp As Object = TryCast(p, Object)
        Dim vPointObjectList As Object = New System.Runtime.InteropServices.VariantWrapper(p)
        NrkSDK.SetStep("Construct Point Group from Point Name Ref List")
        NrkSDK.SetPointNameRefListArg("Point Name List", vPointObjectList)
        NrkSDK.SetCollectionObjectNameArg("Group Name", ptCol, ptGrp)
        NrkSDK.ExecuteStep()
    End Sub
    Public Sub ConstructAPointAtCircleCenter(ByRef cCol As String, ByRef cNm As String, ByRef ptCol As String, ByRef ptGrp As String, ByRef ptTarg As String)
        NrkSDK.SetStep("Construct a Point at Circle Center")
        NrkSDK.SetCollectionObjectNameArg("Circle Name", cCol, cNm)
        NrkSDK.SetPointNameArg("Point Name", ptCol, ptGrp, ptTarg)
        NrkSDK.ExecuteStep()
    End Sub
    'Lines
    Public Sub ConstructLine2Points(ByRef lCol As String, ByRef lName As String, ByRef p1Col As String, ByRef p1Grp As String, ByRef p1Targ As String, ByRef p2Col As String, ByRef p2Grp As String, ByRef p2Targ As String)
        NrkSDK.SetStep("Construct Line 2 Points")
        NrkSDK.SetCollectionObjectNameArg("Line Name", lCol, lName)
        NrkSDK.SetPointNameArg("First Point", p1Col, p1Grp, p1Targ)
        NrkSDK.SetPointNameArg("Second Point", p2Col, p2Grp, p2Targ)
        NrkSDK.ExecuteStep()
    End Sub
    'Frames
    Public Sub ConstructFrame(ByRef fCol As String, ByRef fName As String, ByRef T(,) As Double)
        NrkSDK.SetStep("Construct Frame")
        NrkSDK.SetCollectionObjectNameArg("New Frame Name", fCol, fName)
        Dim vMatrixobj As Object = New System.Runtime.InteropServices.VariantWrapper(T)
        NrkSDK.SetTransformArg("Transform in Working Coordinates", vMatrixobj)
        NrkSDK.ExecuteStep()
    End Sub
    'Other MP Types
    Public Function MakePointNameRefListRuntimeSelect(ByRef msg As String) As String()
        NrkSDK.SetStep("Make a Point Name Ref List - Runtime Select")
        NrkSDK.SetStringArg("User Prompt", msg)
        NrkSDK.ExecuteStep()
        Dim userPtList As Object
        userPtList = Nothing
        NrkSDK.GetPointNameRefListArg("Resultant Point Name List", userPtList)
        Dim a As Array = TryCast(userPtList, Array)
        Dim out(a.Length - 1) As String
        For idx As Integer = 0 To (out.Length - 1)
            out.SetValue(a.GetValue(idx), idx)
        Next
        Return out
    End Function
    Public Function GetWorkingTransformOfObjectFixedXYZ(ByRef col As String, ByRef name As String) As Double(,)
        NrkSDK.SetStep("Get Working Transform of Object (Fixed XYZ)")
        NrkSDK.SetCollectionObjectNameArg("Object Name", col, name)
        NrkSDK.ExecuteStep()
        Dim T As Object = Nothing
        NrkSDK.GetTransformArg("Transform", T)
        Return T
    End Function


    Public Sub TestByRef(ByRef arr() As Double)
        For idx As Integer = 0 To (arr.Length - 1)
            arr(idx) = arr.GetValue(idx) + 1
        Next
    End Sub

    Function Test() As Double()
        Return {1, 2, 4}
    End Function
    'Analysis Operations
    Public Sub TransformObjectsByDeltaAboutWorkingFrame(ByRef colObjNmRefList() As String, ByRef T(,) As Double)
        Dim p(colObjNmRefList.Length - 1)
        For idx As Integer = 0 To (colObjNmRefList.Length - 1)
            p(idx) = colObjNmRefList.ElementAt(idx)
        Next
        Dim vObjectList As Object = New System.Runtime.InteropServices.VariantWrapper(p)
        NrkSDK.SetStep("Transform Objects by Delta (About Working Frame)")
        NrkSDK.SetCollectionObjectNameRefListArg("Objects to Transform", vObjectList)
        Dim vMatrixobj As Object = New System.Runtime.InteropServices.VariantWrapper(T)
        NrkSDK.SetTransformArg("Delta Transform", vMatrixobj)
        NrkSDK.ExecuteStep()
    End Sub
    'Reporting Operations
    'Excel Direct Connect
    'MS Office Reporting Operations
    'Process Flow Operations
    'Scalar Math Operations
    'Vector Math Operations
    'Instrument Operations
    'Cloud Viewer Operations
    'Variables
    'Utility Operations
    Public Sub SetWorkingFrame(ByRef fCol As String, ByRef fName As String)
        NrkSDK.SetStep("Set Working Frame")
        NrkSDK.SetCollectionObjectNameArg("New Working Frame Name", fCol, fName)
        NrkSDK.ExecuteStep()
    End Sub
    Public Sub DeleteObjects(ByRef colObjNameRefList() As String)
        Dim p(colObjNameRefList.Length - 1)
        For idx As Integer = 0 To (colObjNameRefList.Length - 1)
            p(idx) = colObjNameRefList.ElementAt(idx)
        Next
        Dim vObjectList As Object = New System.Runtime.InteropServices.VariantWrapper(p)
        NrkSDK.SetStep("Delete Objects")
        NrkSDK.SetCollectionObjectNameRefListArg("Object Names", vObjectList)
        NrkSDK.ExecuteStep()
    End Sub

End Class
