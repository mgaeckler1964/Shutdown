object ShutdownForm: TShutdownForm
  Left = 407
  Top = 260
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Rechnerabschaltung'
  ClientHeight = 138
  ClientWidth = 490
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 280
    Top = 16
    Width = 18
    Height = 13
    Caption = 'Zeit'
  end
  object LabelCountDown: TLabel
    Left = 272
    Top = 48
    Width = 208
    Height = 46
    Caption = '00:00:00'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -43
    Font.Name = 'Courier New'
    Font.Pitch = fpFixed
    Font.Style = []
    ParentFont = False
  end
  object Image1: TImage
    Left = 16
    Top = 16
    Width = 33
    Height = 41
    Picture.Data = {
      055449636F6E0000010001002020100000000000E80200001600000028000000
      2000000040000000010004000000000080020000000000000000000000000000
      0000000000000000000080000080000000808000800000008000800080800000
      80808000C0C0C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
      FFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCCCCCCCCCCCCCCCCCCCCCCC
      CCCCCCCFFCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCFFCCCCCCCCCCCCCFFFFCCCCCC
      CCCCCCCFFCCCCCCCCCFFFFCCCCFFFFCCCCCCCCCFFCCCCCCCCFCCCCCCCCCCCCFC
      CCCCCCCFFCCCCCCFFCCCCCCCCCCCCCCFFCCCCCCFFCCCCCFCCCCCCCCCCCCCCCCC
      CFCCCCCFFCCCCCFCCCCCCCCFFFCCCCCCCFCCCCCFFCCCCFCCCCCCCCFFFFCCCCCC
      CCFCCCCFFCCCFCCCCCCCCCFFFFCCCCCCCCCFCCCFFCCCFCCCCCCCCCFFFFCCCCCC
      CCCFCCCFFCCCFCCCCCCCCCFFFFCCCCCCCCCFCCCFFCCCFCCCCCCCCCFFFFCCCCCC
      CCCFCCCFFCCFCCCCCCCCCCFFFFCCCCCCCCCCFCCFFCCFCCCCCCCCCCFFFFCCCCCC
      CCCCFCCFFCCFCCCCCCCCCCFFFFCCCCCCCCCCFCCFFCCFCCCCCCCCCCFFFFCCCCCC
      CCCCFCCFFCCCFCCCCCCCCCFFFFCCCCCCCCCFCCCFFCCCFCCCCCCCCCFFFFCCCCCC
      CCCFCCCFFCCCFCCCCCCCCCFFFFCCCCCCCCCFCCCFFCCCFCCCCCCCCCFFFFCCCCCC
      CCCFCCCFFCCCCFCCCCCCCCFFFFCCCCCCCCFCCCCFFCCCCCFCCCCCCCFFFFCCCCCC
      CFCCCCCFFCCCCCFCCCCCCCFFFFCCCCCCCFCCCCCFFCCCCCCFFCCCCCFFFFCCCCCF
      FCCCCCCFFCCCCCCCCFCCCCFFFFCCCCFCCCCCCCCFFCCCCCCCCCFFCCFFFFCCFFCC
      CCCCCCCFFCCCCCCCCCCCCCFFFCCCCCCCCCCCCCCFFCCCCCCCCCCCCCCCCCCCCCCC
      CCCCCCCFFCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFF00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000}
  end
  object LabelAction: TLabel
    Left = 16
    Top = 72
    Width = 3
    Height = 13
  end
  object DateTimePicker: TDateTimePicker
    Left = 320
    Top = 16
    Width = 81
    Height = 21
    CalAlignment = dtaLeft
    Date = 40881.125
    Time = 40881.125
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkTime
    ParseInput = False
    TabOrder = 0
  end
  object ButtonShutdown: TButton
    Left = 8
    Top = 104
    Width = 75
    Height = 25
    Caption = '&Abschalten'
    TabOrder = 1
    OnClick = ButtonShutdownClick
  end
  object ButtonLogoff: TButton
    Tag = 1
    Left = 88
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Ab&melden'
    TabOrder = 2
    OnClick = ButtonShutdownClick
  end
  object ButtonLock: TButton
    Tag = 2
    Left = 168
    Top = 104
    Width = 75
    Height = 25
    Caption = '&Sperren'
    TabOrder = 3
    OnClick = ButtonShutdownClick
  end
  object ButtonRestart: TButton
    Tag = 3
    Left = 248
    Top = 104
    Width = 75
    Height = 25
    Caption = '&Neustart'
    TabOrder = 4
    OnClick = ButtonShutdownClick
  end
  object ButtonClose: TButton
    Left = 408
    Top = 16
    Width = 75
    Height = 25
    Cancel = True
    Caption = '&Beenden'
    TabOrder = 5
    OnClick = ButtonCloseClick
  end
  object ButtonSuspend: TButton
    Tag = 4
    Left = 328
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Energie sparen'
    TabOrder = 6
    OnClick = ButtonShutdownClick
  end
  object ButtonHibernate: TButton
    Tag = 5
    Left = 408
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Ruhezustand'
    TabOrder = 7
    OnClick = ButtonShutdownClick
  end
  object Timer: TTimer
    Enabled = False
    OnTimer = TimerTimer
    Left = 16
    Top = 56
  end
end
