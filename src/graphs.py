from bokeh.plotting import output_file, figure, show, output_notebook

def main():
    pass


def makeGraph():
    output_file("test.html")
    p = figure(height=400, width=400)
    p.line(x=[1, 2, 3], y=[5, 3, 2])

    show(p)

if __name__ == "__main__":
    main()