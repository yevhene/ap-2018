const path = require('path');
const express = require('express');

const markdown = require('./lib/markdown');

const app = express();

app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

app.use('/assets', express.static(
  path.join(__dirname, 'node_modules/github-markdown-css')
));

markdown.routes(app, '/', path.join(__dirname, 'content'));

app.use('/', express.static('content'))

const port = process.env.PORT || 3000;

app.listen(port, () => {
  console.log(`App listening http://localhost:${port} port`)
});
