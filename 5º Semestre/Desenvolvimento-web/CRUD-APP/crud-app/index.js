const express = require('express')
const { randomUUID } = require('crypto')

const porta = 8080


const app = express()
app.use(express.json())

var users = []

app.get("/users", (req, res) => {
    return res.json(users)
})

app.post("/users", (req, res) => {

    var { nome, email } = req.body;

    var user = {
        id: randomUUID(),
        nome: nome, 
        email: email
    }

    users.push(user)

    console.log("Usuario adicionado com sucesso!")
    return res.json(
        {
            mensagem: "Usuario adicionado com sucesso!",
            user: user
        }
    )
})

app.put("/users/:id", (req, res) => {
    var id = req.params.id
    var { nome, email } = req.body;


    users.map( user => {
        if(user.id == id) {
            user.nome = nome,
            user.email = email
        }
    } )

    console.log("Usuario editado com sucesso!")

    return res.json(
        {
            mensagem: "Usuario adicionado com sucesso!",
            users: users
        }
    )
})

app.delete("/users/:id", (req, res) => {
    var id = req.params.id

    users = users.filter( user => {
        return user.id != id
    })

    console.log("Usuario deletado com sucesso!")

    return res.json(
        {
            mensagem: "Usuario deletado com sucesso!",
            users: users
        }
    )
})


app.listen(porta, () => {
    console.log(`Servidor rodando em http://localhost:${porta}`)
})