import yfinance as yf
import streamlit as st
import pandas as pd

st.write(
  '''
  # Simple Stock Pirce App

  Shown are the stock **closing price** and ***volume*** of Google!
  '''
)

google_symbol = 'GOOGL'
apple_symbol = 'AAPL'

ticker_data_google = yf.Ticker(google_symbol)
ticker_data_apple = yf.Ticker(apple_symbol)

ticker_df_google = ticker_data_google.history(period='id', start='2019-5-31', end='2021-5-20')
ticker_df_apple = ticker_data_apple.history(period='id', start='2019-5-31', end='2021-5-20')

# st.line_chart([ticker_df_google.Close, ticker_df_apple.Close])

st.line_chart(ticker_df_google.Close)
st.write(ticker_df_apple.columns)
st.line_chart(ticker_df_apple.Close)