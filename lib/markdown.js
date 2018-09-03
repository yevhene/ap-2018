const fs = require('fs');
const glob = require('glob');
const path = require('path');
const marked = require('marked');

module.exports.routes = function(app, baseRoute, dir) {
  dir = path.join(dir, '/');
  glob.sync(path.join(dir, '**/*.md')).forEach(filePath => {
    const relativePath = filePath.replace(dir, '');
    const route = joinRoute(baseRoute, relativePath);

    app.get(route, (req, res) =>
      render(res, path.join(dir, relativePath))
    );
  });
}

function render(res, file) {
  fs.readFile(file, 'utf8', (_, content) => {
    const html = marked(content);
    res.render('page', { content: html });
  });
}

function joinRoute(baseRoute, relativePath) {
  const file = path.basename(relativePath);
  const dir = path.dirname(relativePath);
  if (file.endsWith('README.md')) {
    return path.join(baseRoute, dir);
  } else {
    return path.join(baseRoute, dir, file);
  }
}


