import server from './server'

server.listen().then(({ url }) =>
  console.log(`Server running at ${url}`)
);