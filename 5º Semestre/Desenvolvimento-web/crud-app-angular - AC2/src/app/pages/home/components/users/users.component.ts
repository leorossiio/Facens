import { Component } from '@angular/core';

@Component({
  selector: 'app-users',
  templateUrl: './users.component.html',
  styleUrls: ['./users.component.css']
})
export class UsersComponent {

  user = [
    { nome: 'Ana', email: 'ana@example.com', senha: 'senha123', status: 'Ativo', editing: false },
    { nome: 'Carlos', email: 'carlos@example.com', senha: 'senha123', status: 'Ativo', editing: false },
    { nome: 'Diego', email: 'carlos@example.com', senha: 'senha123', status: 'Ativo', editing: false },
    { nome: 'Leonardo', email: 'carlos@example.com', senha: 'senha123', status: 'Ativo', editing: false },
    { nome: 'Maria', email: 'carlos@example.com', senha: 'senha123', status: 'Inativo', editing: false }
  ];

  botaoAlterarStatus(user: any) {
    user.status = user.status === 'Ativo' ? 'Inativo' : 'Ativo';
  }

  editarUsuario(user: any) {
    user.editing = !user.editing;
  }

  salvarEdicao(user: any) {
    user.editing = false;
  }

  deletarUsuario(user: any) {
    const index = this.user.indexOf(user);
    if (index !== -1) {
      this.user.splice(index, 1);
    }
  }
  incluirUsuario() {
    const novoUsuario = {
      nome: '',
      email: '',
      senha: '',
      status: 'Ativo',
      editing: true
    };
    this.user.push(novoUsuario);
  }

}