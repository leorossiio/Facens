import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { LoginComponent } from './pages/login/login.component';
import { SignupComponent } from './pages/signup/signup.component';
import { HomeComponent } from './pages/home/home.component';
import { NavbarComponent } from './pages/home/components/navbar/navbar.component';
import { RouterModule } from '@angular/router';
import { UsersComponent } from './pages/home/components/users/users.component';
import { AppRoutingModule } from './app-routing.module';
import { WelcomeComponent } from './pages/home/components/welcome/welcome.component';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';
import { TarefasComponent } from './pages/home/components/tarefas/tarefas.component';
import { AlertComponent } from './shared/alert/alert.component';
import { CommonModule } from '@angular/common';

@NgModule({
  declarations: [
    AppComponent,
    LoginComponent,
    SignupComponent,
    HomeComponent,
    NavbarComponent,
    UsersComponent,
    WelcomeComponent,
    TarefasComponent,
    AlertComponent
  ],
  imports: [
    BrowserModule,
    RouterModule,
    AppRoutingModule,
    FormsModule,
    CommonModule,
    ReactiveFormsModule
  ],
  exports: [
    AlertComponent
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
