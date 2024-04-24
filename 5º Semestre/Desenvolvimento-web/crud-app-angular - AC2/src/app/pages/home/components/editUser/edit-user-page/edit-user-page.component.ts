import { Component, ViewChild } from '@angular/core';
import { NgForm } from '@angular/forms';
import { Router } from '@angular/router';
@Component({
  selector: 'app-edit-user-page',
  templateUrl: './edit-user-page.component.html',
  styleUrls: ['./edit-user-page.component.css']
})
export class EditUserPageComponent {

  novoUsuario = {
    nome: '',
    email: '',
    senha: '',
    funcao: '',
    status: 'Ativo'
  };

  @ViewChild('userForm') userForm!: NgForm;

  constructor(private router: Router) { }

  salvarUsuario() {
    alert(`Novo usuário adicionado:\nNome: ${this.novoUsuario.nome}\nEmail: ${this.novoUsuario.email}\nFunção: ${this.novoUsuario.funcao}\nSenha: ${this.novoUsuario.senha}`);
    this.router.navigate(['/app/users']);
  }
}

