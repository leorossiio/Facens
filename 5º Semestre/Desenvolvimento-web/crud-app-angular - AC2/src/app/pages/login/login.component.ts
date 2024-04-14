import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { UserService } from 'src/app/services/user.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent {

  constructor(private router: Router, private userService: UserService) {}

  email: string = '';
  password: string = '';
  showPassword: boolean = false;  // Adicionado para armazenar o estado de visibilidade da senha

  // Função para alternar a visibilidade da senha
  togglePasswordVisibility() {
    this.showPassword = !this.showPassword;
  }

  login() {
    const emailInput = document.getElementById('typeEmailX');
    const passwordInput = document.getElementById('typePasswordX');

    emailInput?.classList.remove('input-danger');
    passwordInput?.classList.remove('input-danger');

    if (this.email === '') {
        emailInput?.classList.add('input-danger');
        alert('Por favor, preencha o campo de email.');
        return;
    }

    if (this.password === '') {
        passwordInput?.classList.add('input-danger');
        alert('Por favor, preencha o campo de senha.');
        return;
    }

    let users = this.userService.getUsers();
    let user = users.find(user => user.email === this.email && user.senha === this.password);

    if (user) {
        this.router.navigate(["/app"]);
    } else {
        alert('Usuário inválido.');
        this.email = '';
        this.password = '';
    }
}
}
