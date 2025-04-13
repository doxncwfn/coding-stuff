from manim import *

class Node(Scene):
    def construct(self):
        # Create Nodes
        node1 = Circle(radius=0.5, color=BLUE)
        node2 = Circle(radius=0.5, color=BLUE)
        node3 = Circle(radius=0.5, color=BLUE)

        # Position Nodes
        node1.move_to(LEFT * 3)
        node2.next_to(node1, RIGHT, buff = 2)
        node3.next_to(node2, RIGHT, buff = 2)

        # Create Arrows
        arrow1 = Arrow(node1.get_right(), node2.get_left(), buff=0)
        arrow2 = Arrow(node2.get_right(), node3.get_left(), buff=0)

        # Create Labels
        label1 = MathTex("1").move_to(node1)
        label2 = MathTex("2").move_to(node2)
        label3 = MathTex("3").move_to(node3)

        # Display Everything
        self.play(Create(node1), Create(node2), Create(node3))
        self.play(Create(arrow1), Create(arrow2))
        self.play(Write(label1), Write(label2), Write(label3))
        self.wait(1)