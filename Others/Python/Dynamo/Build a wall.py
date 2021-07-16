Build a wall 
import clr

clr.AddReference("RevitNodes")
import Revit
clr.ImportExtensions(Revit.Elements)

clr.AddReference("RevitServices")
import RevitServices
from RevitServices.Persistence import DocumentManager
from RevitServices.Transactions import TransactionManager
doc = DocumentManager.Instance.CurrentDBDocument

clr.AddReference('RevitAPI')
from Autodesk.Revit.DB import XYZ, Line, Wall

x = IN[0]
y = IN[1]
level = UnwrapElement(IN[2])

width = 3

TransactionManager.Instance.EnsureInTransaction(doc)

for i in range(x):
	pt1 = XYZ(width*i, 0, 0)
	pt2 = XYZ(width*(i+1), 0, 0)
	line = Line.CreateBound(pt1, pt2)
	wall = Wall.Create(doc, line, level.Id, False)

for i in range(x):
	pt1 = XYZ(width*i, width*y, 0)
	pt2 = XYZ(width*(i+1), width*y, 0)
	line = Line.CreateBound(pt1, pt2)
	wall = Wall.Create(doc, line, level.Id, False)

for i in range(y):
	pt1 = XYZ(0, width*i, 0)
	pt2 = XYZ(0, width*(i+1), 0)
	line = Line.CreateBound(pt1, pt2)
	wall = Wall.Create(doc, line, level.Id, False)

for i in range(y):
	pt1 = XYZ(width*x, width*i, 0)
	pt2 = XYZ(width*x, width*(i+1), 0)
	line = Line.CreateBound(pt1, pt2)
	wall = Wall.Create(doc, line, level.Id, False)

"""
line1 = Line.CreateBound(pt1, pt2)
line2 = Line.CreateBound(pt1, pt3)
wall1 = Wall.Create(doc, line1, level.Id, False)
wall2 = Wall.Create(doc, line2, level.Id, False)
"""
TransactionManager.Instance.TransactionTaskDone()

OUT = 0