from manim import *
import numpy as np

def line_intersection(line1, line2):
    A, B = np.array(line1)
    C, D = np.array(line2)
    AB = B - A
    CD = D - C

    # Compute determinant
    denom = AB[0] * CD[1] - AB[1] * CD[0]
    if abs(denom) < 1e-10:  # Check for parallel lines
        return None  # No intersection

    # Solve for intersection parameter t
    t = ((C[0] - A[0]) * CD[1] - (C[1] - A[1]) * CD[0]) / denom
    intersection = A + t * AB

    return np.array([intersection[0], intersection[1], 0])

def line_circle_intersection(line: Line, circle: Circle):
    A = np.array(line.get_start())
    B = np.array(line.get_end())

    O = np.array(circle.get_center())
    radius = circle.radius

    AB = B - A
    AO = A - O

    a = np.dot(AB, AB)
    b = 2 * np.dot(AO, AB)
    c = np.dot(AO, AO) - radius**2

    discriminant = b**2 - 4*a*c
    if discriminant < 0:
        return []

    sqrt_disc = np.sqrt(discriminant)
    t1 = (-b + sqrt_disc) / (2*a)
    t2 = (-b - sqrt_disc) / (2*a)

    P1 = A + t1 * AB
    P2 = A + t2 * AB

    intersections = [np.array([P1[0], P1[1], 0])]
    if discriminant > 0:
        intersections.append(np.array([P2[0], P2[1], 0]))

    return intersections

def circle_intersection(circle1, circle2):
    O1 = circle1.get_center()
    O2 = circle2.get_center()
    r1 = circle1.radius
    r2 = circle2.radius

    d = np.linalg.norm(O1 - O2)

    if d > r1 + r2 or d < abs(r1 - r2):
        return []

    a = (r1**2 - r2**2 + d**2) / (2 * d)
    h = np.sqrt(r1**2 - a**2)
    P2 = O1 + a * (O2 - O1) / d
    intersection1 = P2 + h * np.array([O2[1] - O1[1], O1[0] - O2[0], 0]) / d
    intersection2 = P2 - h * np.array([O2[1] - O1[1], O1[0] - O2[0], 0]) / d

    return [intersection1, intersection2]

def outer_circle(A, B, C):
    def circumcenter(A, B, C):
        D = 2 * (A[0] * (B[1] - C[1]) + B[0] * (C[1] - A[1]) + C[0] * (A[1] - B[1]))
        Ux = ((A[0]**2 + A[1]**2) * (B[1] - C[1]) + (B[0]**2 + B[1]**2) * (C[1] - A[1]) + (C[0]**2 + C[1]**2) * (A[1] - B[1])) / D
        Uy = ((A[0]**2 + A[1]**2) * (C[0] - B[0]) + (B[0]**2 + B[1]**2) * (A[0] - C[0]) + (C[0]**2 + C[1]**2) * (B[0] - A[0])) / D
        return np.array([Ux, Uy, 0])
    
    A = A.get_center()
    B = B.get_center()
    C = C.get_center()
    circumcenter = circumcenter(A, B, C)
    r = np.linalg.norm(circumcenter - A)
    circle = Circle(radius=r, color=BLUE).move_to(circumcenter)
    return circle
