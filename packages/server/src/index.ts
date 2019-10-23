import { config } from "dotenv"
import { join } from 'path'
import server from './server'

config({ path: join(__dirname, '.env') })

server.listen(8001).then(({ url }) =>
  console.log(`Server running at ${url}`)
);