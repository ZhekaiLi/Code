Dynamo 常用命令

1.Math
	Math.Round() 取整
	5.4>>5, 5.6>>6, 5.5>>6, -5.5>>-6
2.String
	String.Replace()

3.NurbsCurve.ByPoints(points) #draw a curve according to the input point list

4."add own module":
	import sys
	sys.path.append(r"folder loaction")
	"then can import module in this folder"

5."make python code connected to revit"
	clr.AddReference("RevitNodes")
	from Revit.Elements import  *

	"create sth in a certain level and point":
		FamilyInstance.ByPointAndLevel(family, point, level)

	#Import Revit API
	clr.AddReference("RevitAPI")
	from AutoDesk.Revit.DB import *

	#Import Manager Classes
	clr.AddReference("RevitServices")
	from RevitServices.Persistence import DocumentManager
	from RevitServices.Transactions import TransactionManager

	#Assign Document
	doc = DocumentManager.Instance.CurrentDBDocument

	#Start Transaction
	TransactionManager.Instance.EnsureInTransaction(doc)

	...code

	#End Transaction
	TransactionManager.Instance.TransactionTaskDone()

6.Geometry Conversion Methods:
	Revit to Dynamo:
		ToPoint(), XYZ object to point
		ToVector(), XYZ object to ToVector
		ToProtoType(), Revit geometry object to Dynamo equivalent
	Dynamo to Revit:
		ToXyz(), point to XYZ object
		ToRevitType(), Dynamo geometry object to Revit equivalent


Arc 
	Arc.ByThreePoints(p1, p2, p3)
	Arc.ByCenterPointStartPointSweepAngle(p_center, p_start, angle, normal'vector')
Curve
	Curve.Extrude(curve, direction'vector') >> suface
	Curve.ExtrudeAsSolid(curve, direction) >> solid

Geometry
	Geometry.Rotate()
	Geometry.Translate(geometry, x, y, z)
	Geometry.Mirror()

List	
	List.ShiftIndices(lis, amount) 
		"""
		shift amount indices to right
		EX: List.ShiftIndices([1,2,3,4], 2) >> [3,4,1,2]
		APL: connect points in turn to a closed graph
			Line.ByStartPointEndPoint(lis, List.ShiftIndices(lis, 1))
			= Polygon.ByPoints(lis)
			= PolyCurve.ByPoints(lis, "True")
		"""
	List.Transpose(lis)
		"""
		tranpose the input lis to another
		EX: [[1,2,3], [4,5,6]] >> [[1,4], [2,5], [3,6]]
		"""
Polygon
	Polygon.Center(polygon) >> point #Return geometric center 
	ToPolygon.Edges(polygon) >> edge[] 
		     .Faces(polygon) >> face[] 
		     .Vertices(polygon) >> vertices[]
		     Edge.CurveGeometry(edge) >> curve
		     Face.SurfaceGeometry(face) >> surface
		     Vertex.PointGeometry(vertex) >> point

	#These code cannot be directly written in code block, should through node
 
Solid
	Solid.Area()/Volumn()/Centroid()
	Solid.ByLoft(crossSections'list') >> solid #Create a solid by lofting between input cross section closed curves
	Solid.Chamfer(solid, edges, offest) #Chamfer a solid (倒角)
	Solid.Fillet(solid, edges, radius) #Fillet a solid (圆角)
	Solid.Union(solid, othersolid)/Difference(solid, othersolid)
Surface
	Surface.ByLoft(crossSections)
	Surface.ByPatch(closedCurve)





