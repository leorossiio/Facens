import { Component } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { UserService } from 'src/app/services/user.service';

@Component({
  selector: 'app-signup',
  templateUrl: './signup.component.html',
  styleUrls: ['./signup.component.css']
})

export class SignupComponent {
  signupForm: FormGroup;

  constructor(private formBuilder: FormBuilder, private userService: UserService) {
    this.signupForm = this.formBuilder.group({
      nome: ['', Validators.required],
      email: ['', [Validators.required, Validators.email]],
      senha: ['', [Validators.required, Validators.minLength(8)]],
      confirmaSenha: ['', Validators.required]
    }, { validator: this.passwordMatchValidator });
  }

  passwordMatchValidator(formGroup: FormGroup): any {
    const senha = formGroup.get('senha');
    const confirmaSenha = formGroup.get('confirmaSenha');
    return senha && confirmaSenha && senha.value === confirmaSenha.value ? null : { mismatch: true };
  }

  validateForm(event: MouseEvent) {
    // Inicialize variáveis para os campos de entrada
    const nomeInput = document.getElementById('nome');
    const emailInput = document.getElementById('email');
    const senhaInput = document.getElementById('senha');
    const confirmaSenhaInput = document.getElementById('confirmaSenha');

    // Remove a classe de perigo (input-danger) dos campos de entrada, caso já esteja aplicada
    nomeInput?.classList.remove('input-danger');
    emailInput?.classList.remove('input-danger');
    senhaInput?.classList.remove('input-danger');
    confirmaSenhaInput?.classList.remove('input-danger');

    // Verifica se o formulário é inválido
    if (this.signupForm.invalid) {
      // Adiciona a classe de perigo (input-danger) aos campos de entrada inválidos
      if (!this.signupForm.get('nome')?.valid) {
        nomeInput?.classList.add('input-danger');
      }

      if (!this.signupForm.get('email')?.valid) {
        emailInput?.classList.add('input-danger');
      }

      if (!this.signupForm.get('senha')?.valid) {
        senhaInput?.classList.add('input-danger');
      }

      if (!this.signupForm.get('confirmaSenha')?.valid) {
        confirmaSenhaInput?.classList.add('input-danger');
      }

      // Exibe um alerta para campos inválidos
      alert('Por favor, preencha todos os campos corretamente.');

      // Impede o envio do formulário se for inválido
      event.preventDefault();
    }
  }


  cadastrarUsuario() {
    if (this.signupForm.invalid) {
      alert('Por favor, preencha todos os campos corretamente');
      return;
    }

    const usuario = {
      nome: this.signupForm.value.nome,
      email: this.signupForm.value.email,
      senha: this.signupForm.value.senha
    };

    this.userService.addUser(usuario);
  }
}
