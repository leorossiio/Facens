import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { FormBuilder, FormGroup, Validators } from '@angular/forms'; // Importando FormBuilder e FormGroup
import { UserService } from 'src/app/services/user.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent {
  // Adicionando FormGroup para controlar o formulário
  loginForm: FormGroup; 

  constructor(
    private router: Router, 
    private userService: UserService,
    private formBuilder: FormBuilder // Inicializando FormBuilder
  ) {
    // Inicializando o FormGroup e definindo validadores para os campos
    this.loginForm = this.formBuilder.group({
      email: ['', [Validators.required, Validators.email]],
      password: ['', [Validators.required]]
    });
  }
  
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

    // Utilizando o FormGroup para acessar os valores dos campos email e password
    if (this.loginForm.invalid) {
      // Verificando se o formulário é inválido
      if (this.loginForm.controls['email'].invalid) {
        emailInput?.classList.add('input-danger');
        alert('Por favor, preencha o campo de email corretamente.\nFormato: email@email.com');
        return;
      }
      if (this.loginForm.controls['password'].invalid) {
        passwordInput?.classList.add('input-danger');
        alert('Por favor, preencha o campo de senha.');
        return;
      }
    }

    // Acessando os valores dos campos de email e senha através do FormGroup
    const email = this.loginForm.value.email;
    const password = this.loginForm.value.password;

    let users = this.userService.getUsers();
    let user = users.find(user => user.email === email && user.senha === password);

    if (user) {
        this.router.navigate(["/app"]);
    } else {
        alert('Usuário inválido.');
        // Limpando os campos de email e senha controlados pelo formulário
        this.loginForm.reset();
    }
  }
}
