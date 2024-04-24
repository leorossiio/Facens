import { Component } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-users',
  templateUrl: './users.component.html',
  styleUrls: ['./users.component.css']
})
export class UsersComponent {
  constructor(private router: Router) { }
  user = [
    { nome: 'Ana', email: 'ana@example.com', senha: 'senha123', status: 'Ativo', funcao: 'Engenheiro de FE', editing: false },
    { nome: 'Carlos', email: 'carlos@example.com', senha: 'senha123', status: 'Ativo', funcao: 'Engenheiro de BE', editing: false },
    { nome: 'Diego', email: 'carlos@example.com', senha: 'senha123', status: 'Ativo', funcao: 'Analista de dados', editing: false },
    { nome: 'Leonardo', email: 'carlos@example.com', senha: 'senha123', status: 'Ativo', funcao: 'Líder Técnico', editing: false },
    { nome: 'Maria', email: 'carlos@example.com', senha: 'senha123', status: 'Inativo', funcao: 'Engenheiro de BE', editing: false }
  ];

  botaoAlterarStatus(user: any) {
    user.status = user.status === 'Ativo' ? 'Inativo' : 'Ativo';
  }

  editarUsuario(user: any) {
    this.router.navigate(['/app/editUser', user]); // Supondo que o ID do usuário seja 'id'
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
    this.router.navigate(['/app/addUser']);
  }
}
