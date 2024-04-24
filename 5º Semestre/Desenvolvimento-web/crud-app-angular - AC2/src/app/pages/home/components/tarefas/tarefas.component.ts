import { Component } from '@angular/core';

@Component({
  selector: 'app-tarefas',
  templateUrl: './tarefas.component.html',
  styleUrls: ['./tarefas.component.css']
})
export class TarefasComponent {
  
  tasks = [
    { id: 1, description: 'Tarefa 1', status: 'Não iniciado', editing: false },
    { id: 2, description: 'Tarefa 2', status: 'Não iniciado', editing: false },
    { id: 3, description: 'Tarefa 3', status: 'Não iniciado', editing: false },
    { id: 4, description: 'Tarefa 4', status: 'Não iniciado', editing: false },
    { id: 5, description: 'Tarefa 5', status: 'Não iniciado', editing: false }
  ];

  botaoConcluir(task: any) {
    if (task.status === 'Não iniciado') {
      task.status = 'Em andamento';
    } else if (task.status === 'Em andamento') {
      task.status = 'Concluído';
    } else if (task.status === 'Concluído') {
      task.status = 'Não iniciado';
    }
  }

  editarTarefa(task: any) {
    task.editing = !task.editing;
  }

  salvarEdicao(task: any) {
    task.editing = false;
  }

  deletarTarefa(task: any) {
    const index = this.tasks.indexOf(task);
    if (index !== -1) {
      this.tasks.splice(index, 1);
    }
  }

  incluirTarefa() {
    const novaTarefa = {
      id: this.tasks.length + 1,
      description: '',
      status: 'Não iniciado',
      editing: true
    };
    this.tasks.push(novaTarefa);
  }
  podeIncluirTarefa(): boolean {
    return this.tasks.every(task => !task.editing);
  }  
}
