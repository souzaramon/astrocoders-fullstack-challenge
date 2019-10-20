const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const CopyWebpackPlugin = require('copy-webpack-plugin');
const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: path.join(__dirname, 'lib', 'es6', 'src', 'index.bs.js'),
  mode: isProd ? 'production' : 'development',
  output: {
    path: path.join(__dirname, 'build/'),
    filename: 'index.js',
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: path.join(__dirname, 'public', 'index.html'),
      inject: false
    }),
    new CopyWebpackPlugin([
      { from: path.join(__dirname, 'public') }
    ])
  ],
  devServer: {
    compress: true,
    contentBase: path.join(__dirname, 'build/'),
    port: process.env.PORT || 8000,
    historyApiFallback: true,
  }
}
