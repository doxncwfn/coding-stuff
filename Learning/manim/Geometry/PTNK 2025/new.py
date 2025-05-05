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

class Geometry(Scene):
    def construct(self):
        circle_O = Circle(radius = 2.5, color = BLUE)
        point_O = Dot(circle_O.get_center(), color=WHITE)
        label_O = MathTex("O").next_to(point_O, RIGHT).scale(0.8)
        point_A = Dot(circle_O.point_at_angle(PI/2 +  PI/7), color=WHITE)
        label_A = MathTex("A").next_to(point_A, UP).scale(0.8)
        point_B = Dot(circle_O.point_at_angle(-3 * PI/4 - PI/11), color=WHITE)
        label_B = MathTex("B").next_to(point_B, LEFT + DOWN, buff = 0.1).scale(0.8)
        point_C = Dot(line_circle_intersection(Line(point_A.get_center(), point_O.get_center()), circle_O)[0], color=WHITE)
        label_C = MathTex("C").next_to(point_C, RIGHT + DOWN).scale(0.8)
        point_D = Dot(circle_O.point_at_angle(-PI/4 + PI/11), color=WHITE)
        label_D = MathTex("D").next_to(point_D, RIGHT).scale(0.8)
        AB = Line(point_A.get_center(), point_B.get_center(), color = WHITE)
        BC = Line(point_B.get_center(), point_C.get_center(), color = WHITE)
        CD = Line(point_C.get_center(), point_D.get_center(), color = WHITE)
        DA = Line(point_D.get_center(), point_A.get_center(), color = WHITE)
        self.play(Create(circle_O), Create(point_O), Write(label_O))
        self.play(Create(AB), Create(BC), Create(CD), Create(DA))
        self.play(Create(point_A), Create(point_B), Create(point_D), Create(point_C),
                  Write(label_A), Write(label_B), Write(label_D), Write(label_C))
        BD = Line(point_B.get_center(), point_D.get_center(), color = WHITE)
        point_I = Dot((point_B.get_center() + point_D.get_center())/2, color=WHITE)
        label_I = MathTex("I").next_to(point_I, DOWN/2 + RIGHT/2).scale(0.8)
        self.play(Create(BD))
        self.play(Create(point_I), Write(label_I))
        A_perp = Line(point_A.get_center(), BD.get_projection(point_A.get_center()), color=WHITE)
        B_perp = Line(point_B.get_center(), DA.get_projection(point_B.get_center()), color=WHITE)
        D_perp = Line(point_D.get_center(), AB.get_projection(point_D.get_center()), color=WHITE)
        angle_perpA = RightAngle(A_perp, BD, length=0.3, color=WHITE, quadrant=(-1,-1))
        angle_perpB = RightAngle(B_perp, DA, length=0.3, color=WHITE, quadrant=(-1,-1))
        angle_perpD = RightAngle(D_perp, AB, length=0.3, color=WHITE, quadrant=(-1,-1))
        point_H = Dot(line_intersection([point_B.get_center(), DA.get_projection(point_B.get_center())],
                                    [point_A.get_center(), BD.get_projection(point_A.get_center())]), color=WHITE)
        label_H = MathTex("H").next_to(point_H, DOWN/2 + RIGHT/2).scale(0.8)
        self.play(Create(A_perp), Create(B_perp), Create(D_perp),
                  Create(angle_perpA), Create(angle_perpB), Create(angle_perpD),
                  Create(point_H), Write(label_H))
        self.wait(0.5)
        self.play(FadeOut(A_perp), FadeOut(B_perp), FadeOut(D_perp),
                  FadeOut(angle_perpA), FadeOut(angle_perpB), FadeOut(angle_perpD),
                  label_H.animate.move_to(point_H.get_center() + UP/3 + LEFT/3))
        point_E = Dot(line_circle_intersection(Line(point_A.get_center(), point_I.get_center()), circle_O)[0], color=WHITE)
        label_E = MathTex("E").next_to(point_E, DOWN/2 + RIGHT/2).scale(0.8)
        AE = Line(point_A.get_center(), point_E.get_center(), color=WHITE)
        self.play(Create(AE))
        self.play(Create(point_E), Write(label_E))
        point_K = Dot(AE.get_projection(point_H.get_center()), color=WHITE)
        label_K = MathTex("K").next_to(point_K, UP/2 + RIGHT/2).scale(0.8)
        HK = Line(point_H.get_center(), point_K.get_center(), color=WHITE)
        angle_K = RightAngle(HK, AE, length=0.3, color=WHITE, quadrant=(-1,-1))
        self.play(Create(HK), Create(angle_K))
        self.play(Create(point_K), Write(label_K))
        self.wait(0.5)
        self.play(FadeOut(angle_K))
        CE = Line(point_C.get_center(), point_E.get_center(), color=WHITE)
        EH = Line(point_E.get_center(), point_H.get_center(), color=WHITE)
        KC = Line(point_K.get_center(), point_C.get_center(), color=WHITE)
        self.play(Create(CE), Create(EH), Create(KC))
        self.play(CE.animate.set_color(RED), EH.animate.set_color(RED), KC.animate.set_color(RED), HK.animate.set_color(RED),
                  point_C.animate.set_color(RED), point_E.animate.set_color(RED), point_H.animate.set_color(RED), point_K.animate.set_color(RED),
                  label_C.animate.set_color(RED), label_E.animate.set_color(RED), label_H.animate.set_color(RED), label_K.animate.set_color(RED))
        self.wait(1)
        self.play(point_C.animate.set_color(WHITE), point_E.animate.set_color(WHITE), point_H.animate.set_color(WHITE), point_K.animate.set_color(WHITE),
                  label_C.animate.set_color(WHITE), label_E.animate.set_color(WHITE), label_H.animate.set_color(WHITE), label_K.animate.set_color(WHITE),
                  CE.animate.set_color(WHITE), EH.animate.set_color(WHITE), KC.animate.set_color(WHITE), HK.animate.set_color(WHITE))
        self.play(FadeOut(CE), FadeOut(EH), FadeOut(KC), FadeOut(HK))
        eq1 = MathTex(r"\text{Prove: }IB^2 = ID^2 = IA.IK").to_corner(UP + LEFT).scale(0.8)
        self.play(Write(eq1))
        self.wait(1)
        self.play(FadeOut(eq1))
        
        self.wait(0.5)
        
        p_F = Dot(line_circle_intersection(Line(point_K.get_center(), BD.get_projection(point_K.get_center())), circle_O)[0])
        l_F = MathTex("F").next_to(p_F, DOWN/2 + LEFT/2).scale(0.8)
        AF = Line(point_A.get_center(), p_F.get_center(), color=WHITE)
        angle_BAF = Angle(AB, AF, radius=1.2, color=WHITE, quadrant=(1,1))
        angle_DAE = Angle(AE, DA, radius=1, color=WHITE, quadrant=(1,-1))
        self.play(Create(AF), Create(angle_DAE), Create(angle_BAF))
        self.play(Create(p_F), Write(l_F))
        self.wait(0.5)
        self.play(FadeOut(angle_BAF), FadeOut(angle_DAE))
        KF = Line(point_K.get_center(), p_F.get_center(), color=RED)
        rangle_tmp = RightAngle(KF, BD, length=0.3, color=RED, quadrant=(-1,-1))
        self.play(Create(KF), Create(rangle_tmp))
        self.play(FadeOut(rangle_tmp), FadeOut(KF))
        # Calculate the angle bisector of ∠BAD
        v_AB = point_B.get_center() - point_A.get_center()
        v_AD = point_D.get_center() - point_A.get_center()
        unit_AB = v_AB / np.linalg.norm(v_AB)
        unit_AD = v_AD / np.linalg.norm(v_AD)
        # Calculate the direction of the angle bisector
        bisector_direction = unit_AB + unit_AD
        bisector_direction /= np.linalg.norm(bisector_direction)
        # Define a point on the angle bisector
        bi_tmp = point_A.get_center() + 3 * bisector_direction  # Scale for length
        # Extend the angle bisector to intersect BD
        p_P = Dot(line_intersection([point_A.get_center(), bi_tmp], [point_B.get_center(), point_D.get_center()]))
        AP = Line(point_A.get_center(), p_P.get_center(), color=WHITE)
        KP = Line(point_K.get_center(), p_P.get_center(), color=WHITE)
        angle_BAP = Angle(AB, AP, radius=1.2, color=WHITE, quadrant=(1,1))
        angle_DAP = Angle(AP, DA, radius=1, color=WHITE, quadrant=(1,-1))
        BK = Line(point_B.get_center(), point_K.get_center(), color=WHITE)
        DK = Line(point_D.get_center(), point_K.get_center(), color=WHITE)
        angle_DKP = Angle(KP, DK, radius=0.4, color=WHITE, quadrant=(1,-1))
        angle_BKP = Angle(BK, KP, radius=0.5, color=WHITE, quadrant=(-1,1))

        
        self.play(Create(BK), Create(DK))
        self.play(Create(AP), Create(angle_BAP), Create(angle_DAP))
        self.play(Create(KP), Create(angle_BKP), Create(angle_DKP))
        l_P = MathTex("P").next_to(p_P, DOWN, buff=0.1).scale(0.8)
        self.play(Create(p_P), Write(l_P))
        self.play(FadeOut(angle_BAP), FadeOut(angle_DAP))
        self.play(FadeOut(angle_BKP), FadeOut(angle_DKP))
        
        self.play(point_B.animate.set_color(RED), point_D.animate.set_color(RED), p_P.animate.set_color(RED),
                  label_B.animate.set_color(RED), label_D.animate.set_color(RED), l_P.animate.set_color(RED))
        self.wait(1)
        self.play(point_B.animate.set_color(WHITE), point_D.animate.set_color(WHITE), p_P.animate.set_color(WHITE),
                  label_B.animate.set_color(WHITE), label_D.animate.set_color(WHITE), l_P.animate.set_color(WHITE))
        self.wait(0.5)