from manim import *
import numpy as np

def line_intersection(line1: Line, line2: Line):
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

def circle_intersection(circle1: Circle, circle2: Circle):
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

class Test(Scene):
    def construct(self):
        circle_O = Circle(radius = 2.5, color = BLUE)
        p_O = Dot(circle_O.get_center(), color=WHITE)
        l_O = MathTex("O").next_to(p_O, RIGHT).scale(0.8)
        p_A = Dot(circle_O.point_at_angle(PI/2 +  PI/7), color=WHITE)
        l_A = MathTex("A").next_to(p_A, UP).scale(0.8)
        p_B = Dot(circle_O.point_at_angle(-3 * PI/4 - PI/11), color=WHITE)
        l_B = MathTex("B").next_to(p_B, LEFT + DOWN, buff = 0.1).scale(0.8)
        p_C = Dot(circle_O.point_at_angle(-PI/4 + PI/11), color=WHITE)
        l_C = MathTex("C").next_to(p_C, RIGHT).scale(0.8)
        AB = Line(p_A.get_center(), p_B.get_center(), color = WHITE)
        BC = Line(p_B.get_center(), p_C.get_center(), color = WHITE)
        AC = Line(p_C.get_center(), p_A.get_center(), color = WHITE)
        self.play(Create(circle_O), Create(p_O), Write(l_O))
        self.play(Create(p_A), Create(p_B), Create(p_C),
                  Write(l_A), Write(l_B), Write(l_C),
                  Create(AB), Create(BC), Create(AC))
        self.wait(0.5)        
           
        p_E = Dot(AC.get_projection(p_B.get_center()), color=WHITE)
        l_E = MathTex("E").next_to(p_E, RIGHT, buff = 0.1).scale(0.8)
        p_F = Dot(AB.get_projection(p_C.get_center()), color=WHITE)
        l_F = MathTex("F").next_to(p_F, LEFT + UP, buff = 0.1).scale(0.8)
        BE = Line(p_B.get_center(), p_E.get_center(), color = WHITE)
        BEC = RightAngle(BE, AC, length=0.3, color=WHITE, quadrant=(-1,-1))
        CF = Line(p_C.get_center(), p_F.get_center(), color = WHITE)
        AFC = RightAngle(CF, AB, length=0.3, color=WHITE, quadrant=(-1,-1))
        p_H = Dot(line_intersection([p_E.get_center(), p_B.get_center()], [p_F.get_center(), p_C.get_center()]))
        l_H = MathTex("H").next_to(p_H, RIGHT, buff = 0.2).scale(0.8)
        AH = Line(p_A.get_center(), p_H.get_center(), color = WHITE)
        self.play(Create(BE), Create(BEC), Create(CF), Create(AFC))
        self.play(Create(p_E), Write(l_E), Create(p_F), Write(l_F))
        self.play(FadeOut(BEC), FadeOut(AFC))
        self.play(Create(p_H), Write(l_H))
        
        p_D = Dot(circle_O.point_at_angle(-PI/2 + PI/7), color=WHITE)
        l_D = MathTex("D").next_to(p_D, DOWN).scale(0.8)
        AD = Line(p_A.get_center(), p_D.get_center(), color = WHITE)
        self.play(Create(AD))
        self.play(Create(p_D), Write(l_D))
        
        p_K = Dot(line_circle_intersection(AH, circle_O)[0], color=WHITE)
        l_K = MathTex("K").next_to(p_K, LEFT + DOWN, buff = 0.1).scale(0.8)
        AK = Line(p_A.get_center(), p_K.get_center(), color = WHITE)
        self.play(Create(AK))
        self.play(Create(p_K), Write(l_K))
        
        p_L = Dot(line_intersection([p_B.get_center(), p_C.get_center()], [p_F.get_center(), p_E.get_center()]), color=WHITE)
        l_L = MathTex("L").next_to(p_L, LEFT + DOWN, buff = 0.1).scale(0.8)
        BL = Line(p_B.get_center(), p_L.get_center(), color = WHITE)
        EL = Line(p_E.get_center(), p_L.get_center(), color = WHITE)
        self.play(Create(BL), Create(EL))
        self.play(Create(p_L), Write(l_L))
        p_P = Dot(line_intersection([p_A.get_center(), p_C.get_center()], [p_K.get_center(), p_D.get_center()]), color=WHITE)
        l_P = MathTex("P").next_to(p_P, RIGHT + DOWN, buff = 0.1).scale(0.8)
        CP = Line(p_C.get_center(), p_P.get_center(), color = WHITE)
        KP = Line(p_K.get_center(), p_P.get_center(), color = WHITE)
        AKP = RightAngle(AK, KP, length=0.3, color=WHITE, quadrant=(-1,1))
        HP = Line(p_H.get_center(), p_P.get_center(), color = WHITE)
        self.play(Create(CP), Create(KP), Create(AKP))
        self.play(Create(p_P), Write(l_P))
        
        p_G = Dot(line_intersection([p_A.get_center(), p_K.get_center()], [p_B.get_center(), p_C.get_center()]), color=WHITE)
        l_G = MathTex("G").next_to(p_G, UP + RIGHT, buff = 0.1).scale(0.8)
        AGK = RightAngle(AK, BC, length=0.3, color=WHITE, quadrant=(-1,1))
        self.play(Create(p_G), Write(l_G), Create(AGK))
        
        self.play(FadeOut(AGK), FadeOut(AKP))
        
        AL = Line(p_A.get_center(), p_L.get_center(), color = WHITE)
        p_Q = Dot(line_circle_intersection(AL, circle_O)[0], color=WHITE)
        l_Q = MathTex("Q").next_to(p_Q, LEFT + UP, buff = 0.1).scale(0.8)
        self.play(Create(AL))
        self.play(Create(p_Q), Write(l_Q))
        p_J = Dot((p_A.get_center() + p_H.get_center()) / 2, color=WHITE)
        l_J = MathTex("J").next_to(p_J, RIGHT, buff = 0.1).scale(0.8)
        circle_J = outer_circle(p_A, p_E, p_F)
        self.play(Create(circle_J), Create(p_J), Write(l_J))
        self.play(p_A.animate.set_color(RED), l_A.animate.set_color(RED),
                  p_E.animate.set_color(RED), l_E.animate.set_color(RED),
                  p_F.animate.set_color(RED), l_F.animate.set_color(RED),
                  p_H.animate.set_color(RED), l_H.animate.set_color(RED),
                  p_Q.animate.set_color(RED), l_Q.animate.set_color(RED),
                  p_J.animate.set_color(RED), l_J.animate.set_color(RED),
                  circle_J.animate.set_color(RED))
        self.wait(0.5)
        self.play(p_A.animate.set_color(WHITE), l_A.animate.set_color(WHITE),
                    p_E.animate.set_color(WHITE), l_E.animate.set_color(WHITE),
                    p_F.animate.set_color(WHITE), l_F.animate.set_color(WHITE),
                    p_H.animate.set_color(WHITE), l_H.animate.set_color(WHITE),
                    p_Q.animate.set_color(WHITE), l_Q.animate.set_color(WHITE),
                    p_J.animate.set_color(WHITE), l_J.animate.set_color(WHITE),
                    FadeOut(circle_J))
        self.wait(0.5)
        
        # Section a
        p_I = Dot((p_H.get_center() + p_P.get_center()) / 2, color=WHITE)
        l_I = MathTex("I").next_to(p_I, DOWN, buff = 0.1).scale(0.8)
        EH = Line(p_E.get_center(), p_H.get_center(), color = RED)
        HK = Line(p_H.get_center(), p_K.get_center(), color = RED)
        KP = Line(p_K.get_center(), p_P.get_center(), color = RED)
        PE = Line(p_P.get_center(), p_E.get_center(), color = RED)
        circle_I = Circle(radius=np.linalg.norm(p_I.get_center() - p_H.get_center()), color = BLUE).move_to(p_I.get_center())
        self.play(Create(EH, run_time = 2), Create(HK, run_time = 2),
                  Create(KP, run_time = 2), Create(PE, run_time = 2),
                  Create(circle_I, run_time = 2),
                  p_I.animate.set_color(RED), l_I.animate.set_color(RED))
        self.play(Create(HP))
        self.play(FadeOut(EH), FadeOut(HK), FadeOut(KP), FadeOut(PE), FadeOut(circle_I),
                  p_I.animate.set_color(WHITE), l_I.animate.set_color(WHITE))

        dashed_BC = DashedLine(p_B.get_center(), p_C.get_center(), color = RED)
        self.play(p_I.animate.set_color(RED), l_I.animate.set_color(RED),
                  p_B.animate.set_color(RED), p_C.animate.set_color(RED),
                  l_B.animate.set_color(RED), l_C.animate.set_color(RED))
        self.play(FadeOut(BC))
        self.play(Create(dashed_BC))
        self.wait(0.5)
        self.play(BC.animate.set_color(WHITE),
                  p_B.animate.set_color(WHITE), l_B.animate.set_color(WHITE),
                  p_C.animate.set_color(WHITE), l_C.animate.set_color(WHITE),
                  p_I.animate.set_color(WHITE), l_I.animate.set_color(WHITE),
                  FadeOut(dashed_BC), FadeIn(BC))
        
        # Section b
        p_M = Dot((p_B.get_center() + p_C.get_center()) / 2, color=WHITE)
        l_M = MathTex("M").next_to(p_M, DOWN, buff=0.1).scale(0.8)
        self.play(Create(p_M), Write(l_M))
        
        OM = Line(p_O.get_center(), p_M.get_center(), color=WHITE)
        self.play(Create(OM))
        
        BD = Line(p_B.get_center(), p_D.get_center(), color=WHITE)
        CD = Line(p_C.get_center(), p_D.get_center(), color=WHITE)
        self.play(Create(BD), Create(CD))
        BK = Line(p_B.get_center(), p_K.get_center(), color = WHITE)
        DK = Line(p_D.get_center(), p_K.get_center(), color = WHITE)
        self.play(Create(BK))
        self.play(p_B.animate.set_color(RED), l_B.animate.set_color(RED),
                  p_K.animate.set_color(RED), l_K.animate.set_color(RED),
                  p_C.animate.set_color(RED), l_C.animate.set_color(RED),
                  p_D.animate.set_color(RED), l_D.animate.set_color(RED),
                  BC.animate.set_color(RED), DK.animate.set_color(RED),
                  BK.animate.set_color(RED), CD.animate.set_color(RED))
        self.wait(0.5)
        self.play(p_B.animate.set_color(WHITE), l_B.animate.set_color(WHITE),
                  p_K.animate.set_color(WHITE), l_K.animate.set_color(WHITE),
                  p_C.animate.set_color(WHITE), l_C.animate.set_color(WHITE),
                  p_D.animate.set_color(WHITE), l_D.animate.set_color(WHITE),
                  BC.animate.set_color(WHITE), DK.animate.set_color(WHITE),
                  BK.animate.set_color(WHITE), CD.animate.set_color(WHITE))
        BH = Line(p_B.get_center(), p_H.get_center(), color=WHITE)
        CH = Line(p_C.get_center(), p_H.get_center(), color=WHITE)
        self.play(BD.animate.set_color(RED), CD.animate.set_color(RED),
                  BH.animate.set_color(RED), CH.animate.set_color(RED),
                  p_B.animate.set_color(RED), p_C.animate.set_color(RED),
                  l_B.animate.set_color(RED), l_C.animate.set_color(RED),
                  l_H.animate.set_color(RED), p_H.animate.set_color(RED),
                  l_C.animate.set_color(RED), l_B.animate.set_color(RED),
                  p_D.animate.set_color(RED), l_D.animate.set_color(RED))
        self.wait(0.5)
        self.play(BD.animate.set_color(WHITE), CD.animate.set_color(WHITE),
                  BH.animate.set_color(WHITE), CH.animate.set_color(WHITE),
                  p_B.animate.set_color(WHITE), p_C.animate.set_color(WHITE),
                  l_B.animate.set_color(WHITE), l_C.animate.set_color(WHITE),
                  l_H.animate.set_color(WHITE), p_H.animate.set_color(WHITE),
                  l_C.animate.set_color(WHITE), l_B.animate.set_color(WHITE),
                  p_D.animate.set_color(WHITE), l_D.animate.set_color(WHITE))
        
        dashed_DH = DashedLine(p_D.get_center(), p_H.get_center(), color=RED)
        self.play(Create(dashed_DH),
                  p_H.animate.set_color(RED), l_H.animate.set_color(RED),
                  p_D.animate.set_color(RED), l_D.animate.set_color(RED),
                  p_M.animate.set_color(RED), l_M.animate.set_color(RED))
        self.wait(0.5)
        DH = Line(p_D.get_center(), p_H.get_center(), color=WHITE)
        self.play(Create(DH),
                  p_H.animate.set_color(WHITE), l_H.animate.set_color(WHITE),
                  p_D.animate.set_color(WHITE), l_D.animate.set_color(WHITE),
                  p_M.animate.set_color(WHITE), l_M.animate.set_color(WHITE))
        
        circle_EFK = outer_circle(p_E, p_F, p_K)
        self.play(p_E.animate.set_color(RED), l_E.animate.set_color(RED),
                  p_F.animate.set_color(RED), l_F.animate.set_color(RED),
                  p_K.animate.set_color(RED), l_K.animate.set_color(RED))
        self.play(Create(circle_EFK))
        p_T = Dot(circle_intersection(circle_EFK, circle_O)[0], color=WHITE)
        l_T = MathTex("T").next_to(p_T, DOWN, buff=0.1).scale(0.8)
        self.play(Create(p_T), Write(l_T))
        self.play(p_E.animate.set_color(WHITE), l_E.animate.set_color(WHITE),
                  p_F.animate.set_color(WHITE), l_F.animate.set_color(WHITE),
                  p_K.animate.set_color(WHITE), l_K.animate.set_color(WHITE))
        self.wait(0.5)
        dashed_LT = DashedLine(p_L.get_center(), p_T.get_center(), color=RED)
        self.play(p_L.animate.set_color(RED), l_L.animate.set_color(RED),
                  p_K.animate.set_color(RED), l_K.animate.set_color(RED),
                  p_T.animate.set_color(RED), l_T.animate.set_color(RED),
                  Create(dashed_LT))
        self.wait(0.5)
        self.play(p_L.animate.set_color(WHITE), l_L.animate.set_color(WHITE),
                  p_K.animate.set_color(WHITE), l_K.animate.set_color(WHITE),
                  p_T.animate.set_color(WHITE), l_T.animate.set_color(WHITE),
                  dashed_LT.animate.set_color(WHITE))
        self.wait(0.5)
        dashed_QT = DashedLine(p_Q.get_center(), p_T.get_center(), color=RED)
        self.play(p_Q.animate.set_color(RED), l_Q.animate.set_color(RED),
                  p_T.animate.set_color(RED), l_T.animate.set_color(RED),
                  p_F.animate.set_color(RED), l_F.animate.set_color(RED),
                  p_G.animate.set_color(RED), l_G.animate.set_color(RED),
                  Create(dashed_QT))
        self.wait(0.5)
        self.play(p_Q.animate.set_color(WHITE), l_Q.animate.set_color(WHITE),
                  p_T.animate.set_color(WHITE), l_T.animate.set_color(WHITE),
                  p_F.animate.set_color(WHITE), l_F.animate.set_color(WHITE),
                  p_G.animate.set_color(WHITE), l_G.animate.set_color(WHITE),
                  dashed_QT.animate.set_color(WHITE))
        
        self.wait(2)