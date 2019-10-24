import server from './server'

server.listen(8001).then(({ url }) =>
  console.log(`Server running at ${url}`)
);
