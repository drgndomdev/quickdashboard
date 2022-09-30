from bokeh.plotting import output_file, figure, show, output_notebook
from bokeh.sampledata.stocks import AAPL, GOOG, FB, MSFT, IBM
import pandas as pd
from bokeh.io import curdoc

def main():
    pass


def makeGraph():
    output_file("test.html")
    p = figure(height=400, width=400)
    p.line(x=[1, 2, 3], y=[5, 3, 2])

    show(p)

def createStockGraph():
    dfAAPL = pd.DataFrame(AAPL)
    dfGOOG = pd.DataFrame(GOOG)
    dfFB = pd.DataFrame(FB)
    dfMSFT = pd.DataFrame(MSFT)
    dfIBM = pd.DataFrame(IBM)
    output_file("stocks.html")
    stockGraph = figure(width=800, height=250, x_axis_type="datetime")

    dfAAPL['date'] = pd.to_datetime(dfAAPL['date'])
    dfGOOG['date'] = pd.to_datetime(dfGOOG['date'])
    dfMSFT['date'] = pd.to_datetime(dfMSFT['date'])
    dfIBM['date'] = pd.to_datetime(dfIBM['date'])
    dfFB['date'] = pd.to_datetime(dfFB['date'])

    stockGraph.line(dfAAPL["date"], dfAAPL["close"], color="red", alpha=0.75)
    stockGraph.line(dfGOOG["date"], dfGOOG["close"], color="blue", alpha=0.75)
    stockGraph.line(dfFB["date"], dfFB["close"], color="green", alpha=0.75)
    stockGraph.line(dfMSFT["date"], dfMSFT["close"], color="yellow", alpha=0.75)
    stockGraph.line(dfIBM["date"], dfIBM["close"], color="purple", alpha=0.75)

    show(stockGraph)

if __name__ == "__main__":
    curdoc().theme = "dark_minimal"
    createStockGraph()

    # plotting graphs
    # harea, multiline, quad, varea, vbar