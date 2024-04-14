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
    if (this.signupForm.invalid) {
      event.preventDefault();
      alert('Por favor, preencha todos os campos corretamente.');
      return;
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
