from manim import *
        
class SquareToCircle(Scene):
    def construct(self):
        circle = Circle()
        circle.set_fill(PINK, opacity=0.1)

        square = Square()  # create a square
        square.rotate(PI / 4)  # rotate a certain amount

        self.play(Create(square))  # animate the creation of the square
        self.play(Transform(square, circle))  # interpolate the square into the circle
        self.play(FadeOut(square))  # fade out animation

class Testing(Scene):
    def construct(self):
        name = Tex("Hello World").to_edge(DL, buff = 0.8)
        sq = Square(side_lenght = 2, color = BLUE).shift(RIGHT*2)
        tri =  Triangle().scale(0.7).to_edge(UL, buff = 0.5)