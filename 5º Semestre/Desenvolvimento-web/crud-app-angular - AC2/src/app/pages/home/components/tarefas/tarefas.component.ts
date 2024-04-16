import { Component } from '@angular/core';

@Component({
  selector: 'app-tarefas',
  templateUrl: './tarefas.component.html',
  styleUrls: ['./tarefas.component.css']
})
export class TarefasComponent {
  
  task = [
    { description: 'Tarefa 1', status: 'Não iniciado', editing: false },
    { description: 'Tarefa 2', status: 'Não iniciado', editing: false },
    { description: 'Tarefa 3', status: 'Não iniciado', editing: false },
    { description: 'Tarefa 4', status: 'Não iniciado', editing: false },
    { description: 'Tarefa 5', status: 'Não iniciado', editing: false }
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
    const index = this.task.indexOf(task);
    if (index !== -1) {
      this.task.splice(index, 1);
    }
  }
  incluirTarefa() {
    const novaTarefa = {
        description: '',
        status: 'Não iniciado',
        editing: true
    };
    this.task.push(novaTarefa);
  }
}