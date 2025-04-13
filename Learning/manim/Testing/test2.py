from manim import *
import numpy as np

class OpeningManim(ThreeDScene):
    #Moving Framebox
    def construct(self):
        #Joint Animation
        # ellipse1 = Ellipse(
        #     width=4.0, height=5.0, fill_opacity=0.5, color=BLUE, stroke_width=10
        # ).move_to(LEFT)
        # ellipse2 = ellipse1.copy().set_color(color=RED).move_to(RIGHT)
        # bool_ops_text = MarkupText("<u>Boolean Operation</u>").next_to(ellipse1, UP * 3)
        # ellipse_group = Group(bool_ops_text, ellipse1, ellipse2).move_to(LEFT * 3)
        # self.play(FadeIn(ellipse_group))

        # i = Intersection(ellipse1, ellipse2, color=GREEN, fill_opacity=0.5)
        # self.play(i.animate.scale(0.25).move_to(RIGHT * 5 + UP * 2.5))
        # intersection_text = Text("Intersection", font_size=23).next_to(i, UP)
        # self.play(FadeIn(intersection_text))

        # u = Union(ellipse1, ellipse2, color=ORANGE, fill_opacity=0.5)
        # union_text = Text("Union", font_size=23)
        # self.play(u.animate.scale(0.3).next_to(i, DOWN, buff=union_text.height * 3))
        # union_text.next_to(u, UP)
        # self.play(FadeIn(union_text))

        # e = Exclusion(ellipse1, ellipse2, color=YELLOW, fill_opacity=0.5)
        # exclusion_text = Text("Exclusion", font_size=23)
        # self.play(e.animate.scale(0.3).next_to(u, DOWN, buff=exclusion_text.height * 3.5))
        # exclusion_text.next_to(e, UP)
        # self.play(FadeIn(exclusion_text))

        # d = Difference(ellipse1, ellipse2, color=PINK, fill_opacity=0.5)
        # difference_text = Text("Difference", font_size=23)
        # self.play(d.animate.scale(0.3).next_to(u, LEFT, buff=difference_text.height * 3.5))
        # difference_text.next_to(d, UP)
        # self.play(FadeIn(difference_text))
        # self.play(
        #     FadeOut(ellipse_group),
        #     FadeOut(i),
        #     FadeOut(intersection_text),
        #     FadeOut(u),
        #     FadeOut(union_text),
        #     FadeOut(e),
        #     FadeOut(exclusion_text),
        #     FadeOut(d),
        #     FadeOut(difference_text),
        # )
        
        #Moving Framebox
        # text=MathTex(
        #     "\\frac{d}{dx}f(x)g(x)=","f(x)\\frac{d}{dx}g(x)","+",
        #     "g(x)\\frac{d}{dx}f(x)"
        # )
        # self.play(Write(text))
        # framebox1 = SurroundingRectangle(text[1], buff = .1)
        # framebox2 = SurroundingRectangle(text[3], buff = .1)
        # self.play(
        #     Create(framebox1),
        # )
        # self.wait()
        # self.play(
        #     ReplacementTransform(framebox1,framebox2),
        # )
        # self.wait()
        # self.play(FadeOut(framebox2))
        # self.play(FadeOut(text))
        
        title = Tex(r"doxncwfn is learning Manim")
        basel = MathTex(r"\sum\limits_{i=1}^{n}x_iy_i = \sum\limits_{i=1}^{n}x_i(1 + e^{-\beta_0 - \sum\limits_{j=1}^{p}\hat{\beta}_jX_j})^{-1}")
        VGroup(title, basel).arrange(DOWN)
        self.play(
            Write(title),
            FadeIn(basel, shift=DOWN),
        )
        self.wait()
        transform_title = Tex(r"Okay?")
        transform_title.to_corner(UP + LEFT)

        self.play(
            Transform(title, transform_title),
            LaggedStart(*[FadeOut(obj, shift=DOWN) for obj in basel]),
        )
        self.wait()

        grid = NumberPlane()
        grid_title = Tex(r"Imma creating some grid", font_size=50)
        grid_title.move_to(transform_title)

        self.add(grid)  # Make sure title is on top of grid
        self.play(
            Transform(title, grid_title),
            Create(grid, run_time=3, lag_ratio=0.1),
        )
        self.wait()

        grid_transform_title = Tex(
            r"Non-linear function applied to the grid!"
        )
        grid_transform_title.move_to(grid_title, UL)
        grid.prepare_for_nonlinear_transform()
        self.play(
            grid.animate.apply_function(
                lambda p: p
                          + np.array(
                    [
                        np.sin(p[1]),
                        np.sin(p[0]),
                        0,
                    ]
                )
            ),
            run_time=2,
        )
        self.wait()
        self.play(Transform(grid_title, grid_transform_title))
        self.wait()
        self.play(
            FadeOut(grid),
            FadeOut(grid_title),
        )
        
        t = Tex(r"This is how sin(x) function created:")
        t.to_corner(UP + LEFT)
        self.play(Write(t))
        self.wait()
        self.show_axis()
        self.show_circle()
        self.move_dot_and_draw_curve()
        self.wait(2)
        
        self.clear()
        self.wait()

        self.set_camera_orientation(phi=75 * DEGREES, theta=30 * DEGREES)

        # Add Title
        title = Text("Journey Through Math").to_edge(UP)
        self.play(Write(title))
        self.wait(1)

        # Create 3D Sphere
        sphere = Sphere(radius=2, resolution=(24, 24))
        sphere.set_color_by_gradient(BLUE, GREEN)
        self.play(Create(sphere), run_time=3)
        self.wait(1)

        # Rotate Sphere
        self.play(Rotate(sphere, angle=PI, axis=UP), run_time=2)

        # Create a 2D Graph
        ax = Axes(
            x_range=[-3, 3, 1], y_range=[-2, 2, 1], axis_config={"color": BLUE}
        ).shift(DOWN * 2)
        graph = ax.plot(lambda x: x**2, color=RED)

        # Label the function
        label = MathTex("y = x^2").next_to(graph, UP, buff=0.3)

        self.play(Create(ax), Create(graph), Write(label), run_time=3)
        self.wait(1)

        # Transform Graph into a new function (sin wave)
        new_graph = ax.plot(lambda x: np.sin(PI * x), color=YELLOW)
        new_label = MathTex("y = \sin(\pi x)").next_to(new_graph, UP, buff=0.3)

        self.play(Transform(graph, new_graph), Transform(label, new_label), run_time=3)
        self.wait(2)

        # Move Camera and End Scene
        self.move_camera(phi=60 * DEGREES, theta=45 * DEGREES)
        self.play(FadeOut(sphere, graph, label, ax, title), run_time=2)
        self.wait(1)
        
    def show_axis(self):
        x_start = np.array([-6,0,0])
        x_end = np.array([6,0,0])

        y_start = np.array([-4,-2,0])
        y_end = np.array([-4,2,0])

        x_axis = Line(x_start, x_end)
        y_axis = Line(y_start, y_end)

        self.play(FadeIn(x_axis), FadeIn(y_axis))
        self.add_x_labels()

        self.origin_point = np.array([-4,0,0])
        self.curve_start = np.array([-3,0,0])

    def add_x_labels(self):
        x_labels = [
            MathTex(r"1 \pi"), MathTex(r"2 \pi"),
            MathTex(r"3 \pi"), MathTex(r"4 \pi"),
        ]

        for i in range(len(x_labels)):
            x_labels[i].next_to(np.array([-1 + 2*i, 0, 0]), DOWN)
            self.play(Write(x_labels[i]), run_time = 0.5)

    def show_circle(self):
        circle = Circle(radius=1)
        circle.move_to(self.origin_point)
        self.play(Create(circle))
        self.circle = circle
        self.wait()

    def move_dot_and_draw_curve(self):
        orbit = self.circle
        origin_point = self.origin_point

        dot = Dot(radius=0.08, color=YELLOW)
        dot.move_to(orbit.point_from_proportion(0))
        self.t_offset = 0
        rate = 0.25

        def go_around_circle(mob, dt):
            self.t_offset += (dt * rate)
            # print(self.t_offset)
            mob.move_to(orbit.point_from_proportion(self.t_offset % 1))

        def get_line_to_circle():
            return Line(origin_point, dot.get_center(), color=BLUE)

        def get_line_to_curve():
            x = self.curve_start[0] + self.t_offset * 4
            y = dot.get_center()[1]
            return Line(dot.get_center(), np.array([x,y,0]), color=WHITE, stroke_width=2 )


        self.curve = VGroup()
        self.curve.add(Line(self.curve_start,self.curve_start))
        def get_curve():
            last_line = self.curve[-1]
            x = self.curve_start[0] + self.t_offset * 4
            y = dot.get_center()[1]
            new_line = Line(last_line.get_end(),np.array([x,y,0]), color=YELLOW_D)
            self.curve.add(new_line)

            return self.curve

        dot.add_updater(go_around_circle)

        origin_to_circle_line = always_redraw(get_line_to_circle)
        dot_to_curve_line = always_redraw(get_line_to_curve)
        sine_curve_line = always_redraw(get_curve)

        self.add(dot)
        self.add(orbit, origin_to_circle_line, dot_to_curve_line, sine_curve_line)
        self.wait(8.5)

        dot.remove_updater(go_around_circle)
        self.clear()
        self.wait()

        ax = Axes(
            x_range=[0, 10, 1],
            y_range=[-2, 2, 1],
            axis_config={"color": BLUE},
        )
        labels = ax.get_axis_labels(x_label="x", y_label="Amplitude")

        self.t = 0 

        # Wave function: Superposition of two sine waves
        def wave_function(x, t):
            return np.sin(2 * PI * (x - 0.5 * t)) + 0.5 * np.sin(4 * PI * (x - 0.5 * t))

        wave = ax.plot(lambda x: wave_function(x, self.t), color=YELLOW)

        def update_wave(mob, dt):
            self.t += dt * 2 
            mob.become(ax.plot(lambda x: wave_function(x, self.t), color=YELLOW))

        wave.add_updater(update_wave)

        self.add(ax, labels, wave)
        self.wait(6)

        self.play(FadeOut(wave, ax, labels), run_time=2)