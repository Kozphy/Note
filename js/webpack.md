webpack
===
###### tags: `webpack`
## 建立 webpack.config.js
```javascript=
const path = require('path');
// const MiniCssExtractPlugin = require('mini-css-extract-plugin');

//path.resolve(__dirname, 'dist'); 轉換絕對路徑，在不同作業系統下才不會錯誤
console.log('=>', path.resolve(__dirname, 'src')); // C:\Users\dbdf0\OneDrive\桌面\前端project\六角\javascript training\webpack test\src
console.log('=>>', path.resolve(__dirname, 'dist')); // C:\Users\dbdf0\OneDrive\桌面\前端project\六角\javascript training\webpack test\dist
console.log("=>>>", process.env.NODE_ENV);

module.exports = {
  mode: process.env.NODE_ENV,
  context: path.resolve(__dirname, 'src'), // 只會針對 entry
  entry: {
    index: './index.js',
    about: './about.js'
  },
  output: {
    path: path.resolve(__dirname, 'dist'),
    filename: '[name].js'
  },
  // plugins: [ 
  //   new MiniCssExtractPlugin({
  //     // Options similar to the same options in webpackOptions.output
  //     // both options are optional
  //     filename: 'css/[name].css',
  //     chunkFilename: '[id].css',
  //   }),
  // ],
  module: {
      rules: [
      //   {
      //   test: /\.css$/,
      //   use: [
      //     {
      //       loader: MiniCssExtractPlugin.loader,
      //       options: {
      //         publicPath: './',
      //       },
      //     },
      //     'css-loader',
      //   ],
      // }, 
      {
        test: /\.html$/,
        loader: 'file-loader',
        options: {
          name: '[path][name].[ext]',
        },
      },
      {
        test: /\.(sass|scss)$/i,
        use: [
          // Creates `style` nodes from JS strings
          'style-loader',
          // Translates CSS into CommonJS
          'css-loader',
          'postcss-loader',
          // Compiles Sass to CSS
          'sass-loader',
        ],
      },
    ],
  },
};
```

## 安裝環境(全)
```
npm init
npm install webpack webpack-cli --save-dev
// css Loader 可以解析不是 js 的檔案
npm install --save-dev css-loader
// style loader 
npm i style-loader --save-dev

// Windows 一定要安裝 cross-env
npm install cross-env --save-dev

// MiniCssExtractPlugin
npm install --save-dev mini-css-extract-plugin

// fileLoader
npm install file-loader --save-dev

// sassLoader
npm install sass-loader node-sass --save-dev
// postcss
npm i -D postcss-loader
npm install postcss-cli autoprefixer

// webpack-dev-server
npm install webpack-dev-server --save-dev
```

## cross-env 的變數
```
// 變數
process.env.NODE_ENV

// 設定 process.env.NODE_ENV 的內容
1. cross-env NODE_ENV=development
2. cross-env NODE_ENV=production 
```

## 在 package.json 中加入
1. development 開發時用，產生dist，因為不會壓縮，較快
2. production 專案上線時用，檔案會壓縮，較慢

```
  "scripts": {
    "watch": "cross-env NODE_ENV=development webpack --watch",
    "start": "cross-env NODE_ENV=development webpack",
    "deploy": "cross-env NODE_ENV=production webpack"
    "dev": "cross-env NODE_ENV=development webpack-dev-server --open"

  },
```


---


## 獨立拆分 CSS 檔 MiniCssExtractPlugin
### 安裝
```
npm install --save-dev mini-css-extract-plugin
```
### CSS Loader file.js
```javascript=
import './file.css';
```
### webpack config

```javascript=
  plugins: [
    new MiniCssExtractPlugin({
      // Options similar to the same options in webpackOptions.output
      // both options are optional
      filename: '[name].css',
      chunkFilename: '[id].css',
    }),
  ],
  module: {
    rules: [
      {
        test: /\.css$/,
        use: [
          {
            loader: MiniCssExtractPlugin.loader,
            options: {
              publicPath: '/public/path/to/',
            },
          },
          'css-loader',
        ],
      },
    ],
  },
};
```


---

## FileLoader 搬移 .html 檔案
### 安裝
```
npm install file-loader --save-dev
```
###  file.js
```javascript=
import './file.html';
```
```javascript=
module.exports = {
  module: {
    rules: [
      {
        test: /\.html$/,
        loader: 'file-loader',
        options: {
          name: '[path][name].[ext]',
        },
      },
    ],
  },
};

```

---

## SassLoader
### 安裝
```
npm install sass-loader node-sass --save-dev
```
### sassLoader file.scss
```
import './scss/file.scss'
```
### sassLoader webpack-confing
```
module.exports = {
  module: {
    rules: [
      {
        test: /\.s[ac]ss$/i,
        use: [
          // Creates `style` nodes from JS strings
          'style-loader',
          // Translates CSS into CommonJS
          'css-loader',
          'postcss-loader'
          // Compiles Sass to CSS
          'sass-loader',
        ],
      },
    ],
  },
};
```
### Postcss Loader
```
npm i -D postcss-loader
npm install postcss-cli autoprefixer
```
###  create postcss.config.js
```
module.exports = {
  plugins: [
    require('autoprefixer')
  ]
}
```

---
## webpack-dev-server
### 安裝
```
npm install webpack-dev-server --save-dev
```
### package.json 設定
```javascript=
  "browsersList":{
    "production" : [
      ">0.2%",
      "not dead",
      "not op_mini all"
    ],
    "deveLopment": [
      "last 1 chrome version",
      "last 1 firefox version",
      "last 1 safari version",
      "last 1 ie version"
    ]
  }
```
### webpage.config
```javascript=
devServer: {
    compress: true,
    port: 3000,
    stats: {
    assets: true,
    cached: false,
    chunkModules: false,
    chunkOrigins: false,
    chunks: false,
    colors: true,
    hash: false,
    modules: false,
    reasons: false,
    source: false,
    version: false,
    warnings: false
    },
},

```

---

## babel
### 安裝
```
npm install babel-loader @babel/core @babel/preset-env --save-dev
```

### webpack.config
```
{
    test: /\.(js)$/,
    use: 'babel-loader'
},

```
### .babelrc
```
{
     "presets": ["@babel/preset-env"]
}

```


### 執行
1. watch 自動執行
2. start:執行時要輸入 npm run start
3. deploy: npm run deploy
```
npm start run / deploy / watch
```

